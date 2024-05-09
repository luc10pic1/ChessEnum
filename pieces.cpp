#include "pieces.h"



void Pieces::initialingChessboard(Pieces ** chessboard){
    for(int i=0;i<8;i++){
        chessboard[i]=new Pieces[8];
    }
    Pieces torreB1(ColorPed::white,TypePed::torre,0,7);
    chessboard[0][7]=torreB1;
    Pieces torreB2(ColorPed::white,TypePed::torre,7,7);
    chessboard[7][7]=torreB2;
    Pieces cavalloB1(ColorPed::white,TypePed::cavallo,1,7);
    chessboard[1][7]=cavalloB1;
    Pieces cavalloB2(ColorPed::white,TypePed::cavallo,6,7);
    chessboard[6][7]=cavalloB2;
    Pieces alfiereB1(ColorPed::white,TypePed::alfiere,2,7);
    chessboard[2][7]=alfiereB1;
    Pieces alfiereB2(ColorPed::white,TypePed::alfiere,5,7);
    chessboard[5][7]=alfiereB2;
    Pieces reB(ColorPed::white,TypePed::re,4,7);
    chessboard[4][7]=reB;
    Pieces reginaB(ColorPed::white,TypePed::regina,3,7);
    chessboard[3][7]=reginaB;
    Pieces pedoneB1(ColorPed::white,TypePed::pedone,0,6);
    chessboard[0][6]=pedoneB1;
    Pieces pedoneB2(ColorPed::white,TypePed::pedone,1,6);
    chessboard[1][6]=pedoneB2;
    Pieces pedoneB3(ColorPed::white,TypePed::pedone,2,6);
    chessboard[2][6]=pedoneB3;
    Pieces pedoneB4(ColorPed::white,TypePed::pedone,3,6);
    chessboard[3][6]=pedoneB4;
    Pieces pedoneB5(ColorPed::white,TypePed::pedone,4,6);
    chessboard[4][6]=pedoneB5;
    Pieces pedoneB6(ColorPed::white,TypePed::pedone,5,6);
    chessboard[5][6]=pedoneB6;
    Pieces pedoneB7(ColorPed::white,TypePed::pedone,6,6);
    chessboard[6][6]=pedoneB7;
    Pieces pedoneB8(ColorPed::white,TypePed::pedone,7,6);
    chessboard[7][6]=pedoneB8;
    Pieces torreN1(ColorPed::black,TypePed::torre,0,0);
    chessboard[0][0]=torreN1;
    Pieces torreN2(ColorPed::black,TypePed::torre,7,0);
    chessboard[7][0]=torreN2;
    Pieces cavalloN1(ColorPed::black,TypePed::cavallo,1,0);
    chessboard[1][0]=cavalloN1;
    Pieces cavalloN2(ColorPed::black,TypePed::cavallo,6,0);
    chessboard[6][0]=cavalloN2;
    Pieces alfiereN1(ColorPed::black,TypePed::alfiere,2,0);
    chessboard[2][0]=alfiereN1;
    Pieces alfiereN2(ColorPed::black,TypePed::alfiere,5,0);
    chessboard[5][0]=alfiereN2;
    Pieces reginaN(ColorPed::black,TypePed::regina,3,0);
    chessboard[3][0]=reginaN;
    Pieces reN(ColorPed::black,TypePed::re,4,0);
    chessboard[4][0]=reN;
    Pieces pedoneN1(ColorPed::black,TypePed::pedone,0,1);
    chessboard[0][1]=pedoneN1;
    Pieces pedoneN2(ColorPed::black,TypePed::pedone,1,1);
    chessboard[1][1]=pedoneN2;
    Pieces pedoneN3(ColorPed::black,TypePed::pedone,2,1);
    chessboard[2][1]=pedoneN3;
    Pieces pedoneN4(ColorPed::black,TypePed::pedone,3,1);
    chessboard[3][1]=pedoneN4;
    Pieces pedoneN5(ColorPed::black,TypePed::pedone,4,1);
    chessboard[4][1]=pedoneN5;
    Pieces pedoneN6(ColorPed::black,TypePed::pedone,5,1);
    chessboard[5][1]=pedoneN6;
    Pieces pedoneN7(ColorPed::black,TypePed::pedone,6,1);
    chessboard[6][1]=pedoneN7;
    Pieces pedoneN8(ColorPed::black,TypePed::pedone,7,1);
    chessboard[7][1]=pedoneN8;
}

void Pieces::printChessboard(Pieces ** chessboard){
    std::cout<<"  ";
    for(int i=0;i<8;i++){
        std::cout<<" "<<i<<" ";
    }
    std::cout<<"\n";
    for(int i=0;i<8;i++){
        std::cout<<i<<" ";
        for(int j=0;j<8;j++){
            switch (chessboard[j][i].getColor()) {
                case (ColorPed::white):
                    switch (chessboard[j][i].getTypePed()) {
                        case (TypePed::torre):
                            std::cout << " T ";
                            break;
                        case (TypePed::cavallo):
                            std::cout << " C ";
                            break;
                        case (TypePed::alfiere):
                            std::cout << " A ";
                            break;
                        case (TypePed::re):
                            std::cout << " K ";
                            break;
                        case (TypePed::regina):
                            std::cout << " Q ";
                            break;
                        case (TypePed::pedone):
                            std::cout << " P ";
                            break;
                    }
                    break;
                case (ColorPed::black):
                    switch (chessboard[j][i].getTypePed()) {
                        case (TypePed::torre):
                            std::cout << " t ";
                            break;
                        case (TypePed::cavallo):
                            std::cout << " c ";
                            break;
                        case (TypePed::alfiere):
                            std::cout << " a ";
                            break;
                        case (TypePed::re):
                            std::cout << " k ";
                            break;
                        case (TypePed::regina):
                            std::cout << " q ";
                            break;
                        case (TypePed::pedone):
                            std::cout << " p ";
                            break;
                    }
                    break;
                default:
                    std::cout<<" * ";
            }

        }
        std::cout<<" "<<i<<" ";
        std::cout<<"\n";
    }
    std::cout<<"  ";
    for(int i=0;i<8;i++){
        std::cout<<" "<<i<<" ";
    }
    std::cout<<"\n";
}

bool Pieces::checkKing(Pieces ** chessboard){
    bool result=true;
    bool foundN=false;
    bool foundB=false;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(chessboard[i][j].getTypePed()==TypePed::re){
                if(chessboard[i][j].getColor()==ColorPed::white)
                    foundB=true;
                else
                    foundN=true;
            }
        }
    }
    if(foundN && foundB)
        result=true;
    else if(!foundN) {
        std::cout << "Il bianco ha vinto!!!\n";
        result = false;
    }
    else{
        std::cout<<"Il nero ha vinto!!!\n";
        result=false;
    }
    return result;
}

bool Pieces::isThereObstacle(int a, int b,Pieces ** chessboard) {
    bool result=false;
    if(chessboard[a][b].typePed==TypePed::none){
        result=true;
    }
    return result;
}

bool Pieces::isLegalMoveAlfiere(int n,int m,Pieces ** chessboard){
    int a,b;
    a=x;
    b=y;
    bool result=true;
    while(result && (a!=n||b!=m) && (n<8&&n>=0||m<8&&m>=0)){
        if((a!=n && b==m) || (a==n && b!=m)){
            result=false;
        }
        else{
            if(n>a){
                a++;
                if(m<b){
                    b--;
                }
                if(m>b){
                    b++;
                }
                if(n!=a && m!=b) // controlla che non stia verificando la destination box
                    result= isThereObstacle(a,b,chessboard);
            }
            if(n<a){
                a--;
                if(m<b)
                    b--;
                if(m>b)
                    b++;
                if(n!=a && m!=b)  //r. 196
                    result= isThereObstacle(a,b,chessboard);
            }
        }
    }
    return result;
}

bool Pieces::isLegalMoveTorre(int n, int m,Pieces ** chessboard){
    int a=x;
    int b=y;
    bool result=true;
    if(a==n)
        while(m!=b && result){
            if(m>b){
                b++;
                if(m!=b) // controlla che non stia verificando la destination box
                    result= isThereObstacle(a,b,chessboard);
            }
            if(m<b){
                b--;
                if(m!=b) //r. 227
                    result= isThereObstacle(a,b,chessboard);
            }
        }
    else if(b==m){
        while(n!=a && result){
            if(n>a){
                a++;
                if(n!=a) // controlla che non stia verificando la destination box
                    result= isThereObstacle(a,b,chessboard);
            }
            if(n<a){
                a--;
                if(n!=a) // r.240
                    result= isThereObstacle(a,b,chessboard);
            }
        }
    }
    else{result=false;}
    return result;
}

bool Pieces::isLegalMove(int n, int m,Pieces ** chessboard) { // non controlla la cella di destinazione
    int a=x;
    int b=y;
    bool result=true;
    switch (typePed) {
        case(TypePed::torre):
            result= isLegalMoveTorre(n,m,chessboard);
            break;
        case (TypePed::cavallo):
            if((n==a+1 && (m==b+2 || m==b-2)) || (n==a+2 && (m==b+1 || m==b-1)) || (n==a-1 && (m==b-2 || m==b+2)) || (n==a-2 && (m==b-1 || m==b+1)))
                result=true;
            else{result=false;}
            break;
        case(TypePed::alfiere):
            result= isLegalMoveAlfiere(n,m,chessboard);
            break;
        case(TypePed::pedone):
            if(chessboard[a][b].getColor()==ColorPed::black && m<b)
                result=false;
            if(chessboard[a][b].getColor()==ColorPed::white && m>b)
                result=false;
            while(result && m!=b) {
                if (n == a) {
                    if (abs(m - b) < 3) {
                        if(firstMove) {
                            if (m < b) {
                                b--;
                            }
                            if (m > b) {
                                b++;
                            }
                            result = isThereObstacle(a, b,chessboard);
                        }
                        else{
                            if(abs(m-b)<2){
                                if(m<b)
                                    b--;
                                if(m>b)
                                    b++;
                                result= isThereObstacle(a,b,chessboard);
                            }
                            else{result=false;}
                        }
                    }
                    else{result=false;}
                }
                else{
                    if(abs(a-n)<2&&abs(b-m)<2){
                        result=true;
                        capture=true;
                        b=m;
                    }
                    else{result=false;};
                }
            }
            if(m==b&&n!=a&&!capture)
                result=false;
            break;
        case(TypePed::re):
            if(abs(a-n)<2&&abs(b-m)<2){
                result=true;
            }
            else{result=false;}
            break;
        case(TypePed::regina):
            if(a!=n && b!=m)
                result= isLegalMoveAlfiere(n,m,chessboard);
            else{
                result= isLegalMoveTorre(n,m,chessboard);
            }
            break;
        case(TypePed::none):
            result=false;
            break;
    }
    return result;
}

bool Pieces::destinationBox(int n, int m,Pieces ** chessboard) {
    bool result=true;
    if(chessboard[n][m].typePed!=TypePed::none){
        if(color!=chessboard[n][m].color) {
            result = true;
            capture = true;
        }
        else{result=false;}
    }
    else{
        if(typePed==TypePed::pedone && capture)
            result=false;
        else{result=true;}
    }
    return result;

}

void Pieces::setterPiece(Pieces ** chessboard,int a,int b){
    (chessboard[a][b]).setX(a);
    (chessboard[a][b]).setY(b);
}

void Pieces::substiotionPedone(Pieces ** chessboard,int a,int b) {
    bool right=false;
    while(!right) {
        right=true;
        std::string piece;
        std::cout << "Digitare il nome del pezzo da sostituire con il pedone (esclusi re e pedone): ";
        std::cin >> piece;
        if (piece == "regina") {
            chessboard[a][b].setTypePed(TypePed::regina);
            setterPiece(chessboard, a, b);
        }
        else if(piece=="torre") {
            chessboard[a][b].setTypePed((TypePed::torre));
            setterPiece(chessboard, a, b);
        }
        else if(piece=="cavallo") {
            chessboard[a][b].setTypePed(TypePed::cavallo);
            setterPiece(chessboard, a, b);
        }
        else if(piece=="alfiere") {
            chessboard[a][b].setTypePed((TypePed::alfiere));
            setterPiece(chessboard, a, b);
        }
        else{
            right=false;
            std::cout<<"Pezzo non valido\n";
        }
    }
}

void Pieces::checkScacco(Pieces **chessboard,bool * scMNero, bool* scRNero, bool * scMBianco, bool * scRbianco) {
    int aW,bW,aB,bB;

    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            switch(chessboard[i][j].getTypePed()){
                case(TypePed::re):
                    switch (chessboard[i][j].getColor()) {
                        case(ColorPed::white):
                            aW=i;
                            bW=j;
                            break;
                        case(ColorPed::black):
                            aB=i;
                            bB=j;
                    }
            }
        }
    }
    bool check=false;
    for(int i=0;!check && i<8;i++){ //controllo scacco al re
        for(int j=0;!check &&j<8;j++){
            if(chessboard[i][j].isLegalMove(aW,bW,chessboard) && chessboard[i][j].getColor()==ColorPed::black) {
                *scRNero = true;
                check=true;
            }
            else if(chessboard[i][j].isLegalMove(aB,bB,chessboard) && chessboard[i][j].getColor()==ColorPed::white) {
                *scRbianco = true;
                check = true;
            }
        }
    }
    if(!check){
        *scRNero=false;
        *scRbianco=false;
    }
    if (*scRNero)
        *scMNero = checkScaccoMatto(chessboard, aW, bW, ColorPed::white);
    if (*scRbianco)
        *scMBianco = checkScaccoMatto(chessboard, aB, bB, ColorPed::black);

}

bool Pieces::checkScaccoMatto(Pieces ** chessboard,int a, int b, ColorPed c){
    bool canMoveK=false;
    for(int i=0;i<8;i++){
        for(int j=0;j<8 && !canMoveK;j++){
            if(chessboard[i][j].getTypePed()!=TypePed::none && chessboard[i][j].getColor()!=c) {
                if(chessboard[a][b].isLegalMove((a+1),b,chessboard)) {
                    if (!chessboard[i][j].isLegalMove((a + 1), b, chessboard))
                        canMoveK=true;
                }

            }
        }
    }
    for(int i=0;i<8;i++){
        for(int j=0;j<8 && !canMoveK;j++){
            if(chessboard[i][j].getTypePed()!=TypePed::none && chessboard[i][j].getColor()!=c) {
                if(chessboard[a][b].isLegalMove((a-1),b,chessboard)) {
                    if (!chessboard[i][j].isLegalMove((a-1), b, chessboard))
                        canMoveK=true;
                }

            }
        }
    }
    for(int i=0;i<8;i++){
        for(int j=0;j<8 && !canMoveK;j++){
            if(chessboard[i][j].getTypePed()!=TypePed::none && chessboard[i][j].getColor()!=c) {
                if(chessboard[a][b].isLegalMove(a,b+1,chessboard)) {
                    if (!chessboard[i][j].isLegalMove(a , b+1, chessboard))
                        canMoveK=true;
                }

            }
        }
    }
    for(int i=0;i<8;i++){
        for(int j=0;j<8 && !canMoveK;j++){
            if(chessboard[i][j].getTypePed()!=TypePed::none && chessboard[i][j].getColor()!=c) {
                if(chessboard[a][b].isLegalMove(a,b-1,chessboard)) {
                    if (!chessboard[i][j].isLegalMove(a, b-1, chessboard))
                        canMoveK=true;
                }

            }
        }
    }
    for(int i=0;i<8;i++){
        for(int j=0;j<8 && !canMoveK;j++){
            if(chessboard[i][j].getTypePed()!=TypePed::none && chessboard[i][j].getColor()!=c) {
                if(chessboard[a][b].isLegalMove((a+1),b+1,chessboard)) {
                    if (!chessboard[i][j].isLegalMove((a + 1), b+1, chessboard))
                        canMoveK=true;
                }

            }
        }
    }
    for(int i=0;i<8;i++){
        for(int j=0;j<8 && !canMoveK;j++){
            if(chessboard[i][j].getTypePed()!=TypePed::none && chessboard[i][j].getColor()!=c) {
                if(chessboard[a][b].isLegalMove((a+1),b-1,chessboard)) {
                    if (!chessboard[i][j].isLegalMove((a + 1), b-1, chessboard))
                        canMoveK=true;
                }

            }
        }
    }
    for(int i=0;i<8;i++){
        for(int j=0;j<8 && !canMoveK;j++){
            if(chessboard[i][j].getTypePed()!=TypePed::none && chessboard[i][j].getColor()!=c) {
                if(chessboard[a][b].isLegalMove((a-1),b-1,chessboard)) {
                    if (!chessboard[i][j].isLegalMove((a -1), b-1, chessboard))
                        canMoveK=true;
                }

            }
        }
    }
    for(int i=0;i<8;i++){
        for(int j=0;j<8 && !canMoveK;j++){
            if(chessboard[i][j].getTypePed()!=TypePed::none && chessboard[i][j].getColor()!=c) {
                if(chessboard[a][b].isLegalMove((a-1),b+1,chessboard)) {
                    if (!chessboard[i][j].isLegalMove((a - 1), b+1, chessboard))
                        canMoveK=true;
                }

            }
        }
    }
    if(!canMoveK){
        for(int i=0;i<8 && !canMoveK;i++){
            for(int j=0;j<8 && !canMoveK;j++){
                if(chessboard[i][j].color==c){
                    for(int k=0;k<8;k++){
                        for(int l=0;l<8;l++){
                            if(chessboard[i][j].isLegalMove(k,l,chessboard) && chessboard[i][j].destinationBox(k,l,chessboard)){
                                chessboard[i][j].setX(k);  //cambio coordinate
                                chessboard[i][j].setY(l);
                                Pieces change = chessboard[i][j];
                                chessboard[i][j] = Pieces();
                                Pieces changeA=chessboard[l][k];
                                chessboard[l][k] = change;
                                if(!Pieces::checkScaccoTwo(chessboard))
                                    canMoveK=true;
                                chessboard[i][j]=change;
                                chessboard[l][k]=changeA;
                                chessboard[i][j].setY(j);
                                chessboard[i][j].setX(i);
                            }
                        }
                    }
                }
            }
        }
    }
    return !canMoveK;
}

bool Pieces::checkScaccoTwo(Pieces ** chessboard){
    int aW,bW,aB,bB;
    bool result =false;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            switch(chessboard[i][j].getTypePed()){
                case(TypePed::re):
                    switch (chessboard[i][j].getColor()) {
                        case(ColorPed::white):
                            aW=i;
                            bW=j;
                            break;
                        case(ColorPed::black):
                            aB=i;
                            bB=j;
                    }
            }
        }
    }
    for(int i=0;i<8;i++){ //controllo scacco al re
        for(int j=0;j<8;j++){
            if(chessboard[i][j].isLegalMove(aW,bW,chessboard) && chessboard[i][j].getColor()==ColorPed::black)
                result=true;
            if(chessboard[i][j].isLegalMove(aB,bB,chessboard) && chessboard[i][j].getColor()==ColorPed::white)
                result=true;
        }
    }
    return result;
}
