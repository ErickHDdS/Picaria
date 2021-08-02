#include "Hole.h"

Hole::Hole(QWidget *parent)
        : QPushButton(parent),
          m_state(Hole::EmptyState) ,
          m_row(0), m_col(0) {
    this->updateHole(m_state);

    QObject::connect(this, SIGNAL(stateChanged(State)), this, SLOT(updateHole(State)));
}

Hole::~Hole() {
}

void Hole::setState(State state) {
    if (m_state != state) {
        m_state = state;
        emit stateChanged(state);
    }
}

void Hole::reset() {
    m_state = Hole::EmptyState;
    this->updateHole(m_state);
}

QPixmap Hole::stateToPixmap(State state) {
    switch (state) {
        case Hole::EmptyState:
            return QPixmap(":empty");
        case Hole::RedState:
            return QPixmap(":red");
        case Hole::BlueState:
            return QPixmap(":blue");
        case Hole::SelectableState:
            return QPixmap(":selectable");
        default:
            return QPixmap();
    }
}

// definindo os vizinhos de cada buraco (vetor de buracos, identificacao do jogo (NineHoles '9' ou ThirteenHoles '13')
void Hole::setNeighborhood(Hole** hole, int idGame) {
    int pos;
    for(int index = 0; index <= 12; index++) {
        if(index == 0) {
            pos = index;
            hole[pos]->North      = nullptr;
            hole[pos]->NorthEast  = nullptr;
            hole[pos]->East       = hole[1];

            if(idGame == 9)
                hole[pos]->SouthEast  = hole[6];
            else
                hole[pos]->SouthEast  = hole[3];

            hole[pos]->South      = hole[5];
            hole[pos]->SouthWest  = nullptr;
            hole[pos]->West       = nullptr;
            hole[pos]->NorthWest  = nullptr;
        }

        if(index == 1) {
            pos = index;
            hole[pos]->North      = nullptr;
            hole[pos]->NorthEast  = nullptr;
            hole[pos]->East       = hole[2];

            if(idGame == 9)
                hole[pos]->SouthEast  = hole[7];
            else
                hole[pos]->SouthEast  = hole[4];

            hole[pos]->South        = hole[6];

            if(idGame == 9)
                hole[pos]->SouthWest  = hole[5];
            else
                hole[pos]->SouthWest  = hole[3];

            hole[pos]->West       = hole[0];
            hole[pos]->NorthWest  = nullptr;
        }

        if(index == 2) {
            pos = index;
            hole[pos]->North      = nullptr;
            hole[pos]->NorthEast  = nullptr;
            hole[pos]->East       = nullptr;
            hole[pos]->SouthEast  = nullptr;
            hole[pos]->South      = hole[7];

            if(idGame == 9)
                hole[pos]->SouthWest  = hole[6];
            else
                hole[pos]->SouthWest  = hole[4];

            hole[pos]->West       = hole[1];
        }

        if(index == 3) {
            pos = index;
            if(idGame == 9) {
                hole[pos]->North      = nullptr;
                hole[pos]->NorthEast  = nullptr;
                hole[pos]->East       = nullptr;
                hole[pos]->SouthEast  = nullptr;
                hole[pos]->South      = nullptr;
                hole[pos]->SouthWest  = nullptr;
                hole[pos]->West       = nullptr;
                hole[pos]->NorthWest  = nullptr;
            }
            else {
                hole[pos]->North      = nullptr;
                hole[pos]->NorthEast  = hole[1];
                hole[pos]->East       = nullptr;
                hole[pos]->SouthEast  = hole[6];
                hole[pos]->South      = nullptr;
                hole[pos]->SouthWest  = hole[5];
                hole[pos]->West       = nullptr;
                hole[pos]->NorthWest  = hole[0];
            }
        }

        if(index == 4) {
            pos = index;
            if(idGame == 9) {
                hole[pos]->North      = nullptr;
                hole[pos]->NorthEast  = nullptr;
                hole[pos]->East       = nullptr;
                hole[pos]->SouthEast  = nullptr;
                hole[pos]->South      = nullptr;
                hole[pos]->SouthWest  = nullptr;
                hole[pos]->West       = nullptr;
                hole[pos]->NorthWest  = nullptr;
            }
            else {
                hole[pos]->North      = nullptr;
                hole[pos]->NorthEast  = hole[2];
                hole[pos]->East       = nullptr;
                hole[pos]->SouthEast  = hole[7];
                hole[pos]->South      = nullptr;
                hole[pos]->SouthWest  = hole[6];
                hole[pos]->West       = nullptr;
                hole[pos]->NorthWest  = hole[1];
            }
        }

        if(index == 5) {
            pos = index;
            hole[pos]->North      = hole[0];

            if(idGame == 9)
                hole[pos]->NorthEast  = hole[1];
            else
                hole[pos]->NorthEast  = hole[3];

            hole[pos]->East       = hole[6];

            if(idGame == 9)
                hole[pos]->SouthEast  = hole[11];
            else
                hole[pos]->SouthEast  = hole[8];

            hole[pos]->South      = hole[10];
            hole[pos]->SouthWest  = nullptr;
            hole[pos]->West       = nullptr;
            hole[pos]->NorthWest  = nullptr;
        }

        if(index == 6) {
            pos = index;
            hole[pos]->North      = hole[1];

            if(idGame == 9)
                hole[pos]->NorthEast  = hole[2];
            else
                hole[pos]->NorthEast  = hole[4];

            hole[pos]->East       = hole[7];

            if(idGame == 9)
                hole[pos]->SouthEast  = hole[12];
            else
                hole[pos]->SouthEast  = hole[9];

            hole[pos]->South      = hole[11];

            if(idGame == 9)
                hole[pos]->SouthWest  = hole[10];
            else
                hole[pos]->SouthWest  = hole[8];

            hole[pos]->West       = hole[5];

            if(idGame == 9)
                hole[pos]->NorthWest  = hole[0];
            else
                hole[pos]->NorthWest  = hole[3];
        }

        if(index == 7) {
            pos = index;
            hole[pos]->North      = hole[2];
            hole[pos]->NorthEast  = nullptr;
            hole[pos]->East       = nullptr;
            hole[pos]->SouthEast  = nullptr;
            hole[pos]->South      = hole[12];

            if(idGame == 9)
                hole[pos]->SouthWest  = hole[11];
            else
                hole[pos]->SouthWest  = hole[9];

            hole[pos]->West       = hole[6];

            if(idGame == 9)
                hole[pos]->NorthWest  = hole[1];
            else
                hole[pos]->NorthWest  = hole[4];
        }

        if(index == 8) {
            pos = index;
            if(idGame == 9) {
                hole[pos]->North      = nullptr;
                hole[pos]->NorthEast  = nullptr;
                hole[pos]->East       = nullptr;
                hole[pos]->SouthEast  = nullptr;
                hole[pos]->South      = nullptr;
                hole[pos]->SouthWest  = nullptr;
                hole[pos]->West       = nullptr;
                hole[pos]->NorthWest  = nullptr;
            }
            else {
                hole[pos]->North      = nullptr;
                hole[pos]->NorthEast  = hole[6];
                hole[pos]->East       = nullptr;
                hole[pos]->SouthEast  = hole[11];
                hole[pos]->South      = nullptr;
                hole[pos]->SouthWest  = hole[10];
                hole[pos]->West       = nullptr;
                hole[pos]->NorthWest  = hole[5];
            }

        }
        if(index == 9) {
            pos = index;
            if(idGame == 9) {
                hole[pos]->North      = nullptr;
                hole[pos]->NorthEast  = nullptr;
                hole[pos]->East       = nullptr;
                hole[pos]->SouthEast  = nullptr;
                hole[pos]->South      = nullptr;
                hole[pos]->SouthWest  = nullptr;
                hole[pos]->West       = nullptr;
                hole[pos]->NorthWest  = nullptr;
            }
            else {
                hole[pos]->North      = nullptr;
                hole[pos]->NorthEast  = hole[7];
                hole[pos]->East       = nullptr;
                hole[pos]->SouthEast  = hole[12];
                hole[pos]->South      = nullptr;
                hole[pos]->SouthWest  = hole[11];
                hole[pos]->West       = nullptr;
                hole[pos]->NorthWest  = hole[6];
            }
        }

        if(index == 10) {
            pos = index;
            hole[pos]->North      = hole[5];

            if(idGame == 9)
                hole[pos]->NorthEast  = hole[6];
            else
                hole[pos]->NorthEast  = hole[8];

            hole[pos]->East       = hole[11];
            hole[pos]->SouthEast  = nullptr;
            hole[pos]->South      = nullptr;
            hole[pos]->SouthWest  = nullptr;
            hole[pos]->West       = nullptr;
            hole[pos]->NorthWest  = nullptr;
        }

        if(index == 11) {
            pos = index;
            hole[pos]->North      = hole[6];

            if(idGame == 9)
                hole[pos]->NorthEast  = hole[7];
            else
                hole[pos]->NorthEast  = hole[9];

            hole[pos]->East       = hole[12];
            hole[pos]->SouthEast  = nullptr;
            hole[pos]->South      = nullptr;
            hole[pos]->SouthWest  = nullptr;
            hole[pos]->West       = hole[10];

            if(idGame == 9)
                hole[pos]->NorthWest  = hole[5];
            else
                hole[pos]->NorthWest  = hole[8];
        }

        if(index == 12) {
            pos = index;
            hole[pos]->North      = hole[7];
            hole[pos]->NorthEast  = nullptr;
            hole[pos]->East       = nullptr;
            hole[pos]->SouthEast  = nullptr;
            hole[pos]->South      = hole[12];
            hole[pos]->SouthWest  = nullptr;
            hole[pos]->West       = hole[11];

            if(idGame == 9)
                hole[pos]->NorthWest  = hole[6];
            else
                hole[pos]->NorthWest  = hole[9];
        }
    }
}

void Hole::updateHole(State state) {
    this->setIcon(Hole::stateToPixmap(state));
}
