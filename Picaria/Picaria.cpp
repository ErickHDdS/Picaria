#include "Picaria.h"
#include "ui_Picaria.h"

#include <QDebug>
#include <QMessageBox>
#include <QActionGroup>
#include <QSignalMapper>

int nineHoles = 9;
int thirteenHoles = 13;

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
      m_mode(Picaria::NineHoles),
      m_player(Picaria::RedPlayer),
      m_phase(Picaria::DropPhase) {

    ui->setupUi(this);

    QActionGroup* modeGroup = new QActionGroup(this);
    modeGroup->setExclusive(true);
    modeGroup->addAction(ui->action9holes);
    modeGroup->addAction(ui->action13holes);

    QObject::connect(ui->actionNew, SIGNAL(triggered(bool)), this, SLOT(reset()));
    QObject::connect(ui->actionQuit, SIGNAL(triggered(bool)), qApp, SLOT(quit()));
    QObject::connect(modeGroup, SIGNAL(triggered(QAction*)), this, SLOT(updateMode(QAction*)));

    QObject::connect(modeGroup, SIGNAL(triggered(QAction*)), this, SLOT(setNeighborhoodOfHole()));

    QObject::connect(this, SIGNAL(modeChanged(Picaria::Mode)), this, SLOT(reset()));
    QObject::connect(ui->actionAbout, SIGNAL(triggered(bool)), this, SLOT(showAbout()));

    QSignalMapper* map = new QSignalMapper(this);
    for (int id = 0; id < 13; ++id) {
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

    Hole::setNeighborhood(this->m_holes, nineHoles);

    this->adjustSize();
    this->setFixedSize(this->size());
}

Picaria::~Picaria() {
    delete ui;
}

// este metodo instancia os vizinhos de todos os buracos e passa o tipo do seu jogo
void Picaria::setNeighborhoodOfHole() {
    if(this->mode() == Picaria::NineHoles)
        Hole::setNeighborhood(this->m_holes, nineHoles);
    else
        Hole::setNeighborhood(this->m_holes, thirteenHoles);
}

void Picaria::setMode(Picaria::Mode mode) {
    if (m_mode != mode) {
        m_mode = mode;
        emit modeChanged(mode);
    }
}

void Picaria::switchPlayer() {
    m_player = m_player == Picaria::RedPlayer ?
                    Picaria::BluePlayer : Picaria::RedPlayer;
    this->updateStatusBar();
}

void Picaria::play(int id) {
    Hole* hole = m_holes[id];

    qDebug() << "row: " << hole->row();
    qDebug() << "col: " << hole->col();

    qDebug() << "clicked on: " << hole->objectName();

    hole->setState(player2state(m_player));
    this->switchPlayer();

    if(this->m_phase == Picaria::MovePhase)
        this->moveHole(hole);
    if(this->m_phase == Picaria::DropPhase)
        //this->drop(hole);

    this->updateStatusBar();
}

// PRECISA MELHORAR ESSE CODIGO
void Picaria::moveHole(Hole* hole) {
    if(hole->state() == player2state(this->m_player)) { // verificando se o estado do buraco corresponde a cor do player
      this->m_nextHole = hole;
      this->showOptionsHole(hole);
    }

    if(hole->state() == Hole::SelectableState) {
        hole->setState(player2state(this->m_player));
        if(this->m_nextHole != nullptr) {
            m_nextHole->setState(Hole::EmptyState);
            m_nextHole = nullptr;
        }
        //this->clearOptionsHole();
    }
}

void Picaria::showOptionsHole(Hole* hole) {
    this->clearOptionsHole();   // limpando as opcoes

    if(hole->North->state() == Hole::EmptyState)
        hole->North->setState(Hole::SelectableState);
    if(hole->NorthEast->state() == Hole::EmptyState)
        hole->NorthEast->setState(Hole::SelectableState);
    if(hole->East->state() == Hole::EmptyState)
        hole->East->setState(Hole::SelectableState);
    if(hole->SouthEast->state() == Hole::EmptyState)
        hole->SouthEast->setState(Hole::SelectableState);
    if(hole->South->state() == Hole::EmptyState)
        hole->South->setState(Hole::SelectableState);
    if(hole->SouthWest->state() == Hole::EmptyState)
        hole->SouthWest->setState(Hole::SelectableState);
    if(hole->West->state() == Hole::EmptyState)
        hole->West->setState(Hole::SelectableState);
    if(hole->NorthWest->state() == Hole::EmptyState)
        hole->NorthWest->setState(Hole::SelectableState);
}

void Picaria::clearOptionsHole() {
    int lim;
    if(this->mode() == Picaria::NineHoles)
        lim = 9;
    else
        lim = 13;
    for(int index = 0; index <=lim-1; index++) {
        if(this->m_holes[index]->state() == Hole::SelectableState)
            this->m_holes[index]->setState(Hole::EmptyState);
    }
}

void Picaria::reset() {
    // Reset each hole.
    for (int id = 0; id < 13; ++id) {
        Hole* hole = m_holes[id];
        hole->reset();

        // Set the hole visibility according to the board mode.
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

    // Reset the player and phase.
    m_player = Picaria::RedPlayer;
    m_phase = Picaria::DropPhase;

    // Finally, update the status bar.
    this->updateStatusBar();
}

void Picaria::showAbout() {
    QMessageBox::information(this, tr("Sobre"), tr("Picaria\n\n\n"
                                                "Desenvolvedores:\n\nErick Henrique Dutra de Souza - erickhenriquedds@gmail.com\n\n"
                                                "Lucas Cota Dornelas - lucascdornelas@gmail.com\n\nEngenharia de Computação\nLaboratório de Linguagens de Programação\n"
                                                "2021.1 - CEFET/MG\n"));
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
    QString player(m_player == Picaria::RedPlayer ? "vermelho" : "azul");
    QString phase(m_phase == Picaria::DropPhase ? "colocar" : "mover");

    ui->statusbar->showMessage(tr("Fase de %1: vez do jogador %2").arg(phase).arg(player));
}
