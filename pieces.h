#include <iostream>


enum class ColorPed{
    white,
    black,
    none,
};

enum class TypePed{
    torre,
    pedone,
    alfiere,
    cavallo,
    regina,
    re,
    none,
};

class Pieces{
public:
    Pieces(ColorPed color,TypePed typePed,int x,int y):color(color),typePed(typePed),x(x),y(y){}

    Pieces():color(ColorPed::none),typePed(TypePed::none) {} //costruttore di default

    bool isLegalMove(int n,int m,Pieces ** chessboard); // controlla se la mossa è legale

    bool destinationBox(int n,int m,Pieces ** chessboard); // controlla casella di destinazione

    static void initialingChessboard(Pieces ** chessboard);  // inizializza la scacchiera

    static void printChessboard(Pieces ** chessboard);  // stampa la scacchiera

    static bool checkKing(Pieces ** chessboard); // controlla che non sia finita la partita

    static void substiotionPedone(Pieces ** chessboard,int a,int b); // sostituisce il pedone

    void static checkScacco(Pieces ** chessboard, bool * scMNero, bool* scRNero, bool * scMBianco, bool * scRbianco);


    ColorPed getColor(){
        return color;
    }
    void setColor(ColorPed color){
        this->color=color;
    }

    TypePed getTypePed(){
        return typePed;
    }
    void setTypePed(TypePed typePed){
        this->typePed=typePed;
    }

    bool isCapture(){
        return capture;
    }
    void setCapture(bool capture){
        this->capture=capture;
    }

    int getX(){
        return x;
    }
    void setX(int x){
        this->x=x;
    }

    int getY(){
        return y;
    }
    void setY(int y){
        this->y=y;
    }

    bool isFirstMove(){
        return firstMove;
    }
    void setFirstMove(bool move){
        firstMove=move;
    }


private:
    bool isThereObstacle(int a, int b,Pieces ** chessboard);  // se ci sono ostacoli sul percorso ->isLegalMove
    bool isLegalMoveAlfiere(int n,int m,Pieces ** chessboard);  // ->isLegalMove
    bool isLegalMoveTorre(int n,int m,Pieces ** chessboard);  // ->isLegalMove
    static void setterPiece(Pieces ** chessboard,int a,int b);  // ->substiotionPedone
    static bool checkScaccoMatto(Pieces ** chessboard,int a, int b,ColorPed c); // ->checkScacco
    static  bool checkScaccoTwo(Pieces **chessboard); // ->checkScacco
    ColorPed color;
    TypePed typePed;
    int x;
    int y;
    bool firstMove{true};
    bool capture{false};
};
