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
    this->clearOptionsHole();           // limpa as opcoes de escolha

    if(this->isGameOver())              // verifica se o jogo acabou
        emit gameOver(this->m_player);

    m_player = m_player == Picaria::RedPlayer ?
                Picaria::BluePlayer : Picaria::RedPlayer;
    this->updateStatusBar();
}

void Picaria::play(int id) {
    Hole* hole = m_holes[id];

    /*
    qDebug() << "row: " << hole->row();
    //qDebug() << "col: " << hole->col();
    //qDebug() << "clicked on: " << hole->objectName();

    //hole->setState(player2state(m_player));
    //this->switchPlayer();
    */

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
    if (hole->state() == Hole::EmptyState) {
            hole->setState(player2state(this->m_player));

            ++m_dropCount;
            if (m_dropCount == numPartsPlayer*2)
                m_phase = Picaria::MovePhase;

            this->switchPlayer();
    }
}

/*********************TENTEI MELHORAR, MAS TALVEZ DE PRA MELHORAR AINDA MAIS*****************************************/
void Picaria::moveHole(Hole* hole){
    if(hole->state() == player2state(this->m_player)){
        this->m_nextHole = hole;                        // Proximo buraco a ser tratado
        this->showSelectableOptionsHole(hole);          // Mostrando as opcoes de escolha
    }

    if(hole->state() == Hole::SelectableState){
        hole->setState(player2state(this->m_player));   // atualiza o estado do buraco

        if(this->m_nextHole != nullptr){
             m_nextHole->setState(Hole::EmptyState);    // set estado vazio
             m_nextHole = nullptr;                      // esvazia o buraco que foi tratado
        }
            this->switchPlayer();                       // mudar a vez do jogador
    }
}

void SetSelectableOptionHole(Hole* hole) {
    if(hole != nullptr && (hole->state() == Hole::EmptyState || hole->state() == Hole::SelectableState))
        hole->setState(Hole::SelectableState);
}

void Picaria::showSelectableOptionsHole(Hole* hole){
    this->clearOptionsHole();                   // limpando as opcoes

    SetSelectableOptionHole((hole->North));
    SetSelectableOptionHole((hole->NorthEast));
    SetSelectableOptionHole((hole->East));
    SetSelectableOptionHole((hole->SouthEast));
    SetSelectableOptionHole((hole->South));
    SetSelectableOptionHole((hole->SouthWest));
    SetSelectableOptionHole((hole->West));
    SetSelectableOptionHole((hole->NorthWest));
}

void Picaria::clearOptionsHole(){
    for(int index = 0; index < thirteenHoles; index++){
        if(this->m_holes[index]->state() == Hole::SelectableState)
            this->m_holes[index]->setState(Hole::EmptyState);
    }
}

void Picaria::reset() {
    for (int id = 0; id < thirteenHoles; ++id) {
        Hole* hole = m_holes[id];
        hole->reset();

        switch (id) {
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

Hole* Picaria::holeAt(int row, int col) const {
    if (row >= 0 && row < 3 &&
        col >= 0 && col < 3) {
        int index = row * 3 + col;
        return m_holes[index];
    } else {
        return nullptr;
    }
}

bool checkAlignment(Hole* hole1, Hole* hole2, Picaria::Player player) {
    if((hole1 != nullptr) && (hole1->state() == player2state(player)) && (hole2 != nullptr) && (hole2->state() == player2state(player)))
        return true;
    return false;
}
/*******************************PRINCIPAL****COMECEI A ADAPTAR, MAS FALTA AINDA****************************************************************************/
bool Picaria::isGameOver(){
    bool alignmentAnswer = false;
    for(int id = 0; id < 13; ++id){
        if(this->m_holes[id]->state() == player2state(m_player)){
            if(checkAlignment(this->m_holes[id]->North, this->m_holes[id]->South, m_player))                // VERTICAL
                alignmentAnswer = true;
            else if(checkAlignment(this->m_holes[id]->NorthEast, this->m_holes[id]->SouthWest, m_player))   // DIAGONAL(DA DIREITA PARA ESQUERDA)
                alignmentAnswer = true;
            else if(checkAlignment(this->m_holes[id]->East, this->m_holes[id]->West, m_player))             // HORIZONTAL
                alignmentAnswer = true;
            else if(checkAlignment(this->m_holes[id]->NorthWest, this->m_holes[id]->SouthEast, m_player))   // DIAGONAL(DA ESQUERDA PARA DIREITA)
                alignmentAnswer = true;
        }
    }
    return alignmentAnswer;
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

    /*
     if(m_player == Picaria::RedPlayer == player)
        qDebug() << "RED: ";
    else
        qDebug() << "BLUE: ";
    */

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

    QString space = "                       🎮🕹  Picaria  🕹🎮                       ";

    if(m_player == Picaria::RedPlayer)
        ui->statusbar->showMessage(tr("Phase of:\t\t\t%1%2Player's turn:\t\t\t%3 🔴").arg(phase).arg(space).arg(player));
    else
        ui->statusbar->showMessage(tr("Phase of:\t\t\t%1%2Player's turn:\t\t\t%3 🔵").arg(phase).arg(space).arg(player));
}
