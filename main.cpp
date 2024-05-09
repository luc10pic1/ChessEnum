#include <iostream>
#include "pieces.h"



int main() {
    Pieces **chessboard=new Pieces*[8];
    Pieces *captureBlack=new Pieces[16]; // array per pezzi mangiati dal nero
    Pieces *captureWhite=new Pieces[16]; // array per pezzi mangiati dal bianco
    ColorPed turn=ColorPed::white;
    bool mossaValida;
    bool scMBianco=false;
    bool scRBianco=false;
    bool scMNero=false;
    bool scRNero=false;
    int a,b;
    int c,d;
    int w=0;
    int n=0;
    Pieces::initialingChessboard(chessboard);
    Pieces::printChessboard(chessboard);
    while(!scMBianco && !scMNero){
        mossaValida=true;
        std::cout<<"Inserisci le coordinate del pezzo da spostare"<<std::endl;
        std::cout<<"x: ";
        std::cin>>a;
        std::cout<<"y: ";
        std::cin>>b;
        std::cout<<"Inserisci le coordinate delle casella di destinazione\nx: ";
        std::cin>>c;
        std::cout<<"y: ";
        std::cin>>d;
        if(chessboard[a][b].isLegalMove(c,d,chessboard) && chessboard[a][b].destinationBox(c,d,chessboard) && chessboard[a][b].getColor()==turn){
            if(chessboard[a][b].getTypePed()==TypePed::pedone && (d==0 || d==7))  //sostituzione pedone
                Pieces::substiotionPedone(chessboard,a,b);
            chessboard[a][b].setX(c);  //cambio coordinate
            chessboard[a][b].setY(d);
            Pieces change = chessboard[a][b];
            chessboard[a][b] = Pieces();
            Pieces changeA=chessboard[c][d];
            chessboard[c][d] = change;
            Pieces::checkScacco(chessboard,&scMNero,&scRNero,&scMBianco,&scRBianco);
            if(turn==ColorPed::white && (scMNero || scRNero))
                mossaValida=false;
            if(turn==ColorPed::black && (scMBianco || scRBianco))
                mossaValida=false;
            chessboard[a][b]=change;
            chessboard[c][d]=changeA;
            chessboard[a][b].setY(b);
            chessboard[a][b].setX(a);
        }
        else{mossaValida=false;}
        if(mossaValida){
            if(chessboard[a][b].isCapture()){ // check cattura
                if(turn==ColorPed::white){
                    captureWhite[w]=chessboard[c][d];
                    w++;
                }
                else{
                    captureBlack[n]=chessboard[c][d];
                    n++;
                }
                chessboard[a][b].setCapture(false);
            }
            chessboard[a][b].setFirstMove(false);
            std::cout << "Mossa eseguita\n";
            if(scRBianco)
                std::cout<<"Scacco al re del bianco\n";
            if(scRNero)
                std::cout<<"Scacco al re del nero\n";
            chessboard[a][b].setX(c);  //cambio coordinate
            chessboard[a][b].setY(d);
            Pieces change = chessboard[a][b];
            chessboard[a][b] = Pieces();
            chessboard[c][d] = change;
            Pieces::printChessboard(chessboard);
            if (turn == ColorPed::white)  //cambio turno
                turn = ColorPed::black;
            else
                turn = ColorPed::white;
        }
        else{
            std::cout<<"Mossa inserita non valida\n";
        }

    }
    if(scMNero)
        std::cout<<"Il nero ha vinto!!";
    if(scMBianco)
        std::cout<<"Il bianco ha vinto!!";
}


