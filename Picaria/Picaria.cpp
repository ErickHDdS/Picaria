#include "Picaria.h"
#include "ui_Picaria.h"

#include <QDebug>
#include <QMessageBox>
#include <QActionGroup>
#include <QSignalMapper>

int nineHoles = 9;
int thirteenHoles = 13;
int numPartsPlayer = 3;

Picaria::Player state2player(Hole::State state) {
    switch (state) {
    case Hole::RedState:
        return Picaria::RedPlayer;
    case Hole::BlueState:
        return Picaria::BluePlayer;
    default:
        Q_UNREACHABLE();
    }
}

Hole::State player2state(Picaria::Player player) {
    return player == Picaria::RedPlayer ? Hole::RedState : Hole::BlueState;
}

Picaria::Picaria(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::Picaria),
      m_mode(Picaria::ThirteenHoles),
      m_player(Picaria::RedPlayer),
      m_phase(Picaria::DropPhase),
      m_dropCount(0){

    ui->setupUi(this);

    QActionGroup* modeGroup = new QActionGroup(this);
    modeGroup->setExclusive(true);
    modeGroup->addAction(ui->action9holes);
    modeGroup->addAction(ui->action13holes);

    QObject::connect(ui->actionNew, SIGNAL(triggered(bool)), this, SLOT(reset()));
    QObject::connect(ui->actionQuit, SIGNAL(triggered(bool)), qApp, SLOT(quit()));
    QObject::connect(modeGroup, SIGNAL(triggered(QAction*)), this, SLOT(updateMode(QAction*)));
    QObject::connect(modeGroup, SIGNAL(triggered(QAction*)), this, SLOT(setNeighborhood()));

    QObject::connect(this, SIGNAL(modeChanged(Picaria::Mode)), this, SLOT(reset()));
    QObject::connect(ui->actionAbout, SIGNAL(triggered(bool)), this, SLOT(showAboutPanel()));
    QObject::connect(this, SIGNAL(gameOver(Picaria::Player)), this, SLOT(showEndGamePanel(Picaria::Player)));

    QSignalMapper* map = new QSignalMapper(this);
    for (int id = 0; id < thirteenHoles; ++id) {
        QString holeName = QString("hole%1").arg(id+1, 2, 10, QChar('0'));
        Hole* hole = this->findChild<Hole*>(holeName);
        Q_ASSERT(hole != nullptr);

        m_holes[id] = hole;
        map->setMapping(hole, id);
        QObject::connect(hole, SIGNAL(clicked(bool)), map, SLOT(map()));
    }


#if QT_VERSION < QT_VERSION_CHECK(6,0,0)
    QObject::connect(map, SIGNAL(mapped(int)), this, SLOT(play(int)));
#else
    QObject::connect(map, SIGNAL(mappedInt(int)), this, SLOT(play(int)));
#endif

    this->reset();

    Hole::setNeighborhood(this->m_holes, thirteenHoles);
    this->m_nextHole = nullptr;
    this->adjustSize();
    this->setFixedSize(this->size());
}

Picaria::~Picaria() {
    delete ui;
}

void Picaria::setMode(Picaria::Mode mode) {
    if (m_mode != mode) {
        m_mode = mode;
        emit modeChanged(mode);
    }
}

void Picaria::setNeighborhood(){
    if(this->mode() == Picaria::NineHoles)
        Hole::setNeighborhood(this->m_holes, nineHoles);
    else
        Hole::setNeighborhood(this->m_holes, thirteenHoles);
}

void Picaria::switchPlayer() {
    this->clearOptionsHole();                   // limpa as opcoes de escolha

    if(this->isEndGame())                       // verifica se o jogo acabou
        emit gameOver(this->m_player);

    m_player = m_player == Picaria::RedPlayer ?
                Picaria::BluePlayer : Picaria::RedPlayer;
    this->updateStatusBar();
}

void Picaria::play(int id) {
    Hole* hole = m_holes[id];

    Q_ASSERT(hole != nullptr);

    switch (this->m_phase) {
        case Picaria::DropPhase:
            this->dropHole(hole);
            break;
        case Picaria::MovePhase:
            this->moveHole(hole);
            break;
        default:
            Q_UNREACHABLE();
    }
}

void Picaria::dropHole(Hole* hole) {
    if (m_phase == Picaria::DropPhase && hole->state() == Hole::EmptyState) {
            hole->setState(player2state(this->m_player));

            ++m_dropCount;
            if (m_dropCount == numPartsPlayer*2)
                m_phase = Picaria::MovePhase;

            this->switchPlayer();
    }
}

void Picaria::moveHole(Hole* hole){
    if(m_phase == Picaria::MovePhase){
        switch (hole->state()) {
            case (Hole::SelectableState):
                hole->setState(player2state(this->m_player));           // atualiza o estado do buraco
                if(this->m_nextHole != nullptr) {
                    this->m_nextHole->setState(Hole::EmptyState);       // setando o antigo buraco para estado vazio
                    this->m_nextHole = nullptr;                         // esvazia o buraco que foi tratado
                }
                this->switchPlayer();                                   // verificar se houve o fim de jogo e mudar o player
                break;

            case (Hole::BlueState):
                if(hole->state()==player2state(m_player)) {
                    this->m_nextHole = hole;                            // Proximo buraco a ser tratado
                    this->showSelectableOptionsHole(m_nextHole);        // Mostrando as opcoes de escolha
                 }
                 break;

            case (Hole::RedState):
                if(hole->state()==player2state(m_player)) {
                    this->m_nextHole = hole;                            // Proximo buraco a ser tratado
                    this->showSelectableOptionsHole(m_nextHole);
                }                                                       // Mostrando as opcoes de escolha
                break;

            default:
                break;
        }
    }
}

void SetSelectableOptionHole(Hole* hole) {
    if(hole != nullptr && (hole->state() == Hole::EmptyState || hole->state() == Hole::SelectableState))
        hole->setState(Hole::SelectableState);
}

void Picaria::showSelectableOptionsHole(Hole* hole){
    this->clearOptionsHole();                           // limpando as opcoes

    // setando as opcoes de movimentos do player
    SetSelectableOptionHole((hole->North));
    SetSelectableOptionHole((hole->NorthEast));
    SetSelectableOptionHole((hole->East));
    SetSelectableOptionHole((hole->SouthEast));
    SetSelectableOptionHole((hole->South));
    SetSelectableOptionHole((hole->SouthWest));
    SetSelectableOptionHole((hole->West));
    SetSelectableOptionHole((hole->NorthWest));
}

// limpando as opcoes de movimentos do player
void Picaria::clearOptionsHole(){
    for(int index = 0; index < thirteenHoles; index++){
        if(this->m_holes[index]->state() == Hole::SelectableState)
            this->m_holes[index]->setState(Hole::EmptyState);
    }
}

void Picaria::reset() {
    for (int index = 0; index < thirteenHoles; ++index) {
        Hole* hole = m_holes[index];
        hole->reset();

        switch (index) {
        case 3:
        case 4:
        case 8:
        case 9:
            hole->setVisible(m_mode == Picaria::ThirteenHoles);
            break;
        default:
            break;
        }
    }

    this->m_dropCount = 0;
    if(m_player == Picaria::RedPlayer)
        m_player = Picaria::RedPlayer;
    else
        m_player = Picaria::BluePlayer;
    m_phase = Picaria::DropPhase;

    this->updateStatusBar();
}

// verificar se o hole que o player mexeu possui vizinho
bool checkNeighborhoodOfHole(Hole* hole, Picaria::Player player) {
    if((hole != nullptr) && (hole->state() == player2state(player)))
        return true;
    else
        return false;
}

bool Picaria::isEndGame(){
    int countAliggnmentNorthSouth, countAliggnmentNorthEastSouthWest, countAliggnmentEastWest, countAliggnmentNorthWestSouthEast;

    for(int index = 0; index < (this->mode() == Picaria::NineHoles ? nineHoles : thirteenHoles); ++index) {     // verificando se todos os buracos possuem vizinhos da mesma cor
        countAliggnmentNorthSouth = 1, countAliggnmentNorthEastSouthWest = 1, countAliggnmentEastWest = 1, countAliggnmentNorthWestSouthEast = 1;
        if(this->m_holes[index]->state() == player2state(m_player)){
            if(this->mode() == Picaria::NineHoles) {
                while((index == 3) || (index == 4) || (index == 8) || (index == 9))                             // Se for NineHoles, esses buracos nao existem
                        index++;
            }

            if(checkNeighborhoodOfHole(this->m_holes[index]->North, m_player))                                  // VERIFICAR SE EXISTEM VIZINHOS NA VERTICAL
                countAliggnmentNorthSouth++;
            if(checkNeighborhoodOfHole(this->m_holes[index]->South, m_player))
                countAliggnmentNorthSouth++;

            if(checkNeighborhoodOfHole(this->m_holes[index]->NorthEast, m_player))                              // VERIFICAR SE EXISTEM VIZINHOS NA DIAGONAL(DA DIREITA PARA ESQUERDA)
                countAliggnmentNorthEastSouthWest++;
            if(checkNeighborhoodOfHole(this->m_holes[index]->SouthWest, m_player))
                countAliggnmentNorthEastSouthWest++;

            if(checkNeighborhoodOfHole(this->m_holes[index]->East, m_player))                                   // VERIFICAR SE EXISTEM VIZINHOS NA HORIZONTAL
                countAliggnmentEastWest++;
            if(checkNeighborhoodOfHole(this->m_holes[index]->West, m_player))
                countAliggnmentEastWest++;

            if(checkNeighborhoodOfHole(this->m_holes[index]->NorthWest, m_player))                              // VERIFICAR SE EXISTEM VIZINHOS NA DIAGONAL(DA ESQUERDA PARA DIREITA)
                countAliggnmentNorthWestSouthEast++;
            if(checkNeighborhoodOfHole(this->m_holes[index]->SouthEast, m_player))
                countAliggnmentNorthWestSouthEast++;
        }

        if((countAliggnmentNorthSouth == numPartsPlayer) || (countAliggnmentNorthEastSouthWest == numPartsPlayer) || (countAliggnmentEastWest == numPartsPlayer) || (countAliggnmentNorthWestSouthEast == numPartsPlayer))
            return true;
    }

    return false;
}


void Picaria::showAboutPanel() {
    QMessageBox::information(this, tr("About"), tr("🎮🕹  Picaria  🎮🕹\n\n🤯 This is a strategy game, where two players face off, where your goal is to line up your three pieces in a row, regardless of direction. 🤯\n\n"
                                                "Developers:\n\n🖥 Erick Henrique Dutra de Souza - erickhenriquedds@gmail.com 📧\n\n"
                                                "🖥 Lucas Cota Dornelas - lucascdornelas@gmail.com 📧\n\nComputer Engineering\nProgramming Languages Laboratory\n"
                                                "2021.1 - CEFET/MG\n"));
}

void Picaria::showEndGamePanel(Player player) {
    QString playerWinner = nullptr;
    QString playerLoser = nullptr;

    switch (player) {
    case Picaria::RedPlayer:
        playerWinner = QString(m_player == Picaria::RedPlayer ? "Red"  : "Blue");
        playerLoser = QString(m_player == Picaria::RedPlayer ? "Blue" : "Red");
        break;

    case Picaria::BluePlayer:
        playerWinner = QString(m_player == Picaria::BluePlayer ? "Blue" : "Red");
        playerLoser = QString(m_player == Picaria::BluePlayer ? "Red" : "Blue");
        break;
    default:
        Q_UNREACHABLE();
    }

    QMessageBox::information(this, tr("End Game 🌴⭐🍀"), tr("Player: %1 won the game 🥇.\nDon't discourage player %2 🥈, you are able to beat him in the next match.\nStart playing now! 👊").arg(playerWinner).arg(playerLoser), tr("Play Again"));
    this->reset();
}

void Picaria::updateMode(QAction* action) {
    if (action == ui->action9holes)
        this->setMode(Picaria::NineHoles);
    else if (action == ui->action13holes)
        this->setMode(Picaria::ThirteenHoles);
    else
        Q_UNREACHABLE();
}

void Picaria::updateStatusBar() {
    QString player(m_player == Picaria::RedPlayer ? "Red." : "Blue.");
    QString phase(m_phase == Picaria::DropPhase ? "to place" : " to move.");

    QString space = "\t\t\t\t\t\t\t\t🎮🕹  Picaria  🕹🎮\t\t\t\t\t\t\t\t";

    if(m_player == Picaria::RedPlayer)
        ui->statusbar->showMessage(tr("Phase of:\t\t\t%1%2Player's turn:\t\t\t%3 🔴").arg(phase).arg(space).arg(player));
    else
        ui->statusbar->showMessage(tr("Phase of:\t\t\t%1%2Player's turn:\t\t\t%3 🔵").arg(phase).arg(space).arg(player));
}
