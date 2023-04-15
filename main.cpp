#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <conio.h>
#include<windows.h>

using namespace std;

void gotoxy(int x, int y){
    COORD coord;
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void bersihlayar(){
    for(int a=0;a<90;a++)
    {
        for(int b=0;b<=40;b++)
        {
            gotoxy(a,b);cout<<" ";
        }
    }
}

void bersihmenu(){
    for(int a=0;a<80;a++)
    {
        for(int b=8;b<=30;b++)
        {
            gotoxy(a,b);cout<<" ";
        }
    }
}

void inputMatriks(int matriks[10][10], int baris,int kolom){
    for(int i=0; i<baris; i++){
        for(int j=0; j<kolom; j++){
            cout<<"m"<<i+1<<j+1<<" : ";cin >> matriks[i][j];
        }
    }

}

void tampilMatriks(int matriks[10][10], int baris, int kolom){
    for(int i=0; i<baris; i++){
        cout <<"+";
        for(int j=0; j<kolom; j++){
            cout <<"-------+";
        }
        break;
    }
    cout<<endl;
    for(int i=0; i<baris; i++){
        cout <<"| ";
        for(int j=0; j<kolom; j++){
            cout << matriks[i][j] ;
            if(j < kolom){
                cout <<"\t|";
            }
            if(j==kolom-1){
                cout <<endl;
                for(int x=0; x<baris; x++){
                    cout<<"+";
                    for(int y=0; y<kolom; y++){
                        cout <<"-------+";
                        if(y ==kolom-1){
                            cout <<endl;
                        }
                    }
                    break;
                }
            }
        }
    }

}

void penjumlahan(int matriks1[10][10], int matriks2[10][10], int hasil[10][10], int baris1, int kolom2){
    //tampil operasi matriks
    cout << "\nOperasi Penjumlahan Matriks 1 + Matriks 2\n";
    for(int i=0; i<baris1; i++){
        for(int j=0; j<kolom2; j++){
            cout << matriks1[i][j] <<"+"<< matriks2[i][j]<<"\t";
            if(j == kolom2-1){
                cout<<endl;
            }
        }
    }
    //operasi penjumlahan
    for(int i=0; i<baris1; i++){
        for(int j=0; j<kolom2; j++){
            hasil[i][j] = matriks1[i][j] + matriks2[i][j];
        }
    }
}

void pengurangan(int matriks1[10][10], int matriks2[10][10], int hasil[10][10], int baris1, int kolom2){
    //tampil operasi matriks
    cout << "\nOperasi Pengurangan Matriks 1 - Matriks 2\n";
    for(int i=0; i<baris1; i++){
        for(int j=0; j<kolom2; j++){
            cout << matriks1[i][j] <<"-"<< matriks2[i][j]<<"\t";
            if(j == kolom2-1){
                cout<<endl;
            }
        }
    }
   // operasi pengurangan
    for(int i=0; i<baris1; i++){
        for(int j=0; j<kolom2; j++){
            hasil[i][j] = matriks1[i][j] - matriks2[i][j];
        }
    }
}

void perkalianSkalar(int matriks[10][10],int hasil[10][10], int baris,int kolom,int skalar){
    //inisialisasi matriks hasil = 0
    for(int i=0; i<baris; i++){
            for(int j=0; j<kolom; j++){
                hasil[i][j] = 0;
            }
    }
    //tampil operasi matriks
    cout << "\nOperasi Perkalian Matriks dan Skalar\n";
    for(int i=0; i<baris; i++){
        for(int j=0; j<kolom; j++){
            cout << matriks[i][j] <<"x"<< skalar<<"\t";
            if(j == kolom-1){
                cout<<endl;
            }
        }
    }
    //operasi perkalian
    for(int i=0; i<baris; i++){
        for(int j=0; j<kolom; j++){
            hasil[i][j] = matriks[i][j]*skalar;
        }
    }
}

void perkalian(int matriks1[10][10], int matriks2[10][10], int hasil[10][10], int baris1,int kolom1,int baris2,int kolom2){
    //inisialisasi matriks hasil = 0
    for(int i=0; i<baris1; i++){
            for(int j=0; j<kolom2; j++){
                hasil[i][j] = 0;
            }
    }
    //tampil operasi matriks
    cout << "\nOperasi Perkalian Matriks 1 x Matriks 2\n";
    for(int i=0; i<baris1; i++){
        for(int j=0; j<kolom2; j++){
            for(int k=0; k<kolom1;k++){
                cout << matriks1[i][k] <<"."<< matriks2[k][j];
                if(k<baris2-1){
                    cout<<"+";
                }
                if(k==baris2-1){
                    cout<<"\t";
                    if(j==kolom2-1){
                        cout<<endl;
                    }
                }
            }
        }
    }
    //operasi perkalian
    for(int i=0; i<baris1; i++){
        for(int j=0; j<kolom2; j++){
            for(int k=0; k<kolom1; k++){
                hasil[i][j] += matriks1[i][k]*matriks2[k][j];
            }
        }
    }

}

int det22(int matriks[10][10]){
    int det = 0;
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            matriks[i][j];
        }
    }
    det = matriks[0][0]*matriks[1][1]-matriks[0][1]*matriks[1][0];
    return det;
}

int det33(int matriks[10][10]){
    int det = 0;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            matriks[i][j];
        }
    }
    det =
    matriks[0][0]*matriks[1][1]*matriks[2][2]+
    matriks[0][1]*matriks[1][2]*matriks[2][0]+
    matriks[0][2]*matriks[1][0]*matriks[2][1]-
    matriks[0][2]*matriks[1][1]*matriks[2][0]-
    matriks[0][0]*matriks[1][2]*matriks[2][1]-
    matriks[0][1]*matriks[1][0]*matriks[2][2];

    return det;

}

void operasiDeterminan22(int matriks[10][10], int det){
    int baris=2;
    int kolom = 2;
    for(int i=0; i<baris; i++){
        for(int j=0; j<kolom; j++){
            matriks[i][j];
        }
    }
    cout<<"Determinan = ("<<matriks[0][0]<<"."<<matriks[1][1]<<") - ("<<matriks[0][1]<<"."<<matriks[1][0]<<")\n";
    cout<<"\t   = ("<<matriks[0][0]*matriks[1][1]<<") - ("<<matriks[0][1]*matriks[1][0]<<")\n";
    cout<<"\t   = "<< det;


}

void operasiDeterminan33(int matriks[10][10], int det){
    int baris=3;
    int kolom = 3;
    for(int i=0; i<baris; i++){
        for(int j=0; j<kolom; j++){
            matriks[i][j];
        }
    }

    cout<<"Determinan = ("<<
    matriks[0][0]<<"."<<matriks[1][1]<<"."<<matriks[2][2]<<"+"<<
    matriks[0][1]<<"."<<matriks[1][2]<<"."<<matriks[2][0]<<"+"<<
    matriks[0][2]<<"."<<matriks[1][0]<<"."<<matriks[2][1]<<") - ("<<
    matriks[0][2]<<"."<<matriks[1][1]<<"."<<matriks[2][0]<<"+"<<
    matriks[0][0]<<"."<<matriks[1][2]<<"."<<matriks[2][1]<<"+"<<
    matriks[0][1]<<"."<<matriks[1][0]<<"."<<matriks[2][2]<<")\n";

    cout<<"\t   = ("<<
    matriks[0][0]*matriks[1][1]*matriks[2][2]<<"+"<<
    matriks[0][1]*matriks[1][2]*matriks[2][0]<<"+"<<
    matriks[0][2]*matriks[1][0]*matriks[2][1]<<") - ("<<
    matriks[0][2]*matriks[1][1]*matriks[2][0]<<"+"<<
    matriks[0][0]*matriks[1][2]*matriks[2][1]<<"+"<<
    matriks[0][1]*matriks[1][0]*matriks[2][2]<<")\n";

    cout<<"\t   = ("<<
    matriks[0][0]*matriks[1][1]*matriks[2][2]+
    matriks[0][1]*matriks[1][2]*matriks[2][0]+
    matriks[0][2]*matriks[1][0]*matriks[2][1]<<") - ("<<
    matriks[0][2]*matriks[1][1]*matriks[2][0]+
    matriks[0][0]*matriks[1][2]*matriks[2][1]+
    matriks[0][1]*matriks[1][0]*matriks[2][2]<<")\n";

    cout<<"\t   = "<<det;
}

void invers22(int matriks[10][10], int hasil[10][10], int det){
    int baris=2;
    int kolom = 2;
    int temp;
    string keterangan[2][2]={"d","-b","-c","a"};
    float float_matriks[10][10];
    float float_hasil[10][10];
    float perDet = 1/(float)det;

    matriks[0][1] = -matriks[0][1];
    matriks[1][0] = -matriks[1][0];
    temp = matriks[0][0];
    matriks[0][0] = matriks[1][1];
    matriks[1][1] = temp;

    cout<<"\nOperasi invers matriks 2x2"<<endl;
    for(int i=0; i<baris; i++){
        cout <<"\t+";
        for(int j=0; j<kolom; j++){
            cout <<"-------+";
        }
        break;
    }
    cout<<endl;
    cout<<"1/det .\t";
    for(int i=0; i<baris; i++){
        cout<<"| ";
        for(int j=0; j<kolom; j++){
            cout<<keterangan[i][j];
            if(j < kolom){
                cout <<"\t| ";
            }
            if(j==kolom-1){
                cout<<endl;
                cout<<"\t";
                for(int x=0; x<baris; x++){
                    cout<<"+";
                    for(int y=0; y<kolom; y++){
                        cout <<"-------+";
                        if(y ==kolom-1){
                            cout <<endl;
                            cout<<"\t";
                        }
                    }
                    break;
                }
            }
        }
    }
    cout<<endl;
    for(int i=0; i<baris; i++){
        cout <<"\t+";
        for(int j=0; j<kolom; j++){
            cout <<"-------+";
        }
        break;
    }
    cout<<endl;
    cout<<"1/"<<det<<" .\t";
    for(int i=0; i<baris; i++){
        cout<<"| ";
        for(int j=0; j<kolom; j++){
            matriks[i][j];
            float_matriks[i][j] = (float)matriks[i][j] ;
            cout<<float_matriks[i][j];
            if(j < kolom){
                cout <<"\t| ";
            }
            if(j==kolom-1){
                cout<<endl;
                cout<<"\t";
                for(int x=0; x<baris; x++){
                    cout<<"+";
                    for(int y=0; y<kolom; y++){
                        cout <<"-------+";
                        if(y ==kolom-1){
                            cout <<endl;
                            cout<<"\t";
                        }
                    }
                    break;
                }
            }
        }
    }

    cout<<endl;
    cout<<"Matriks Invers 2x2"<<endl;
    for(int i=0; i<baris; i++){
        cout <<"+";
        for(int j=0; j<kolom; j++){
            cout <<"-------+";
        }
        break;
    }
    cout<<endl;

    for(int i=0; i<baris; i++){
        cout<<"| ";
        for(int j=0; j<kolom; j++){
            float_hasil[i][j] = (float)hasil[i][j];
            float_hasil[i][j] = perDet*float_matriks[i][j];
            cout<<setprecision(2)<<float_hasil[i][j];
            if(j < kolom){
                cout <<"\t|";
            }
            if(j==kolom-1){
                cout <<endl;
                for(int x=0; x<baris; x++){
                    cout<<"+";
                    for(int y=0; y<kolom; y++){
                        cout <<"-------+";
                        if(y ==kolom-1){
                            cout <<endl;
                        }
                    }
                    break;
                }
            }
        }
    }
}

void invers33(int m_adjoin[10][10], int det){
    int baris = 3;
    int kolom = 3;
    float float_matriks[10][10];
    float float_hasil[10][10];
    float perDet = 1/(float)det;

    cout<<"\nOperasi invers matriks 3x3"<<endl<<endl;

    cout<<"1/det . Matriks Adjoin"<<endl<<endl;
    for(int i=0; i<baris; i++){
        cout <<"\t+";
        for(int j=0; j<kolom; j++){
            cout <<"-------+";
        }
        break;
    }
    cout<<endl;
    cout<<"1/"<<det<<" .\t";
    for(int i=0; i<baris; i++){
        cout<<"| ";
        for(int j=0; j<kolom; j++){

            float_matriks[i][j] = (float)m_adjoin[i][j] ;
            cout<<float_matriks[i][j];

            if(j < kolom){
                cout <<"\t| ";
            }
            if(j==kolom-1){
                cout<<endl;
                cout<<"\t";
                for(int x=0; x<baris; x++){
                    cout<<"+";
                    for(int y=0; y<kolom; y++){
                        cout <<"-------+";
                        if(y ==kolom-1){
                            cout <<endl;
                            cout<<"\t";
                        }
                    }
                    break;
                }
            }
        }
    }

    cout <<endl;

    cout<<endl;
    cout<<"Matriks Invers 3x3"<<endl;
    for(int i=0; i<baris; i++){
        cout <<"+";
        for(int j=0; j<kolom; j++){
            cout <<"-------+";
        }
        break;
    }
    cout<<endl;

    for(int i=0; i<baris; i++){
        cout<<"| ";
        for(int j=0; j<kolom; j++){
            float_hasil[i][j] = perDet*float_matriks[i][j];
            cout<<setprecision(2)<<float_hasil[i][j];
            if(j < kolom){
                cout <<"\t|";
            }
            if(j==kolom-1){
                cout <<endl;
                for(int x=0; x<baris; x++){
                    cout<<"+";
                    for(int y=0; y<kolom; y++){
                        cout <<"-------+";
                        if(y ==kolom-1){
                            cout <<endl;
                        }
                    }
                    break;
                }
            }
        }
    }
}

void transpose(int matriks[10][10], int hasil[10][10], int baris, int kolom){

    for(int i=0; i<baris; i++){
        for(int j=0; j<kolom; j++){
            hasil[j][i] = matriks[i][j];
        }
    }
}

void adjoin22(int matriks[10][10], int hasil[10][10]){
    int baris = 2;
    int kolom = 2;
    int minor[10][10];
    int kov[10][10];

    minor[0][0] = matriks[1][1]; //a 00
    minor[0][1] = matriks[1][0]; //b 01
    minor[1][0] = matriks[0][1]; //c 10
    minor[1][1] = matriks[0][0]; //d 11

    cout << "\nMatriks Minor" <<endl;
    for(int i=0; i<baris; i++){
        for(int j=0; j<kolom; j++){
            cout<<"M"<<i+1<<j+1<<" = "<< minor[i][j];
            cout<<endl;
        }
    }
    tampilMatriks(minor,baris,kolom);

    kov[0][0] = minor[0][0];
    kov[0][1] = minor[0][1] * -1;
    kov[1][0] = minor[1][0] * -1;
    kov[1][1] = minor[1][1];

    cout << "\nMatriks Kofaktor" <<endl;

    cout << "   +\t   -" <<endl;
    cout << "   -\t   +" <<endl;
    tampilMatriks(kov,baris,kolom);

    cout << "\nMatriks Adjoin = Transpose Matriks Kofaktor" <<endl;
    transpose(kov, hasil, baris, kolom);
    tampilMatriks(hasil, baris, kolom);
}

void adjoin33(int matriks[10][10], int hasil[10][10]){
    int baris = 3;
    int kolom = 3;
    int minor[10][10];
    int kov[10][10];

    minor[0][0] = (matriks[1][1] * matriks[2][2]) - (matriks[2][1] * matriks[1][2]);
    minor[0][1] = (matriks[1][0] * matriks[2][2]) - (matriks[2][0] * matriks[1][2]);
    minor[0][2] = (matriks[1][0] * matriks[2][1]) - (matriks[2][0] * matriks[1][1]);
    minor[1][0] = (matriks[0][1] * matriks[2][2]) - (matriks[2][1] * matriks[0][2]);
    minor[1][1] = (matriks[0][0] * matriks[2][2]) - (matriks[2][0] * matriks[0][2]);
    minor[1][2] = (matriks[0][0] * matriks[2][1]) - (matriks[2][0] * matriks[0][1]);
    minor[2][0] = (matriks[0][1] * matriks[1][2]) - (matriks[1][1] * matriks[0][2]);
    minor[2][1] = (matriks[0][0] * matriks[1][2]) - (matriks[1][0] * matriks[0][2]);
    minor[2][2] = (matriks[0][0] * matriks[1][1]) - (matriks[1][0] * matriks[0][1]);

    cout << "\nMatriks Minor" <<endl;
    for(int i=0; i<baris; i++){
        for(int j=0; j<kolom; j++){
            cout<<"M"<<i+1<<j+1<<" = "<< minor[i][j];
            cout<<endl;
        }
    }
    tampilMatriks(minor,baris,kolom);

    kov[0][0] = minor[0][0];
    kov[0][1] = minor[0][1] * -1;
    kov[0][2] = minor[0][2];
    kov[1][0] = minor[1][0] * -1;
    kov[1][1] = minor[1][1];
    kov[1][2] = minor[1][2] * -1;
    kov[2][0] = minor[2][0];
    kov[2][1] = minor[2][1] * -1;
    kov[2][2] = minor[2][2];

    cout << "\nMatriks Kofaktor" <<endl;

    cout << "   +\t   -\t   +" <<endl;
    cout << "   -\t   +\t   -" <<endl;
    cout << "   +\t   -\t   +" <<endl;
    tampilMatriks(kov,baris,kolom);

    cout << "\nMatriks Adjoin = Transpose Matriks Kofaktor" <<endl;
    transpose(kov, hasil, baris, kolom);
    tampilMatriks(hasil, baris, kolom);
}

int main(){
    int pilih, skalar;
    int baris1, kolom1, baris2, kolom2;
    int matriks1[10][10];
    int matriks2[10][10];
    int hasil[10][10];
    int det = 0;
    do{
        system("cls");
        bersihlayar();
        gotoxy(25,2);cout << "[]====================================[]";
        gotoxy(25,3);cout << "||        Matriks Calculator          ||";
        gotoxy(25,4);cout << "|| Nama   : Dirchamsyah               ||";
        gotoxy(25,5);cout << "|| NIM    : A11.2021.13610            ||";
        gotoxy(25,6);cout << "[]====================================[]";
        gotoxy(25,7);cout << "||                                    ||";
        gotoxy(25,8);cout << "||            MENU                    ||";
        gotoxy(25,9);cout << "|| 1. Operasi Matriks                 ||";
        gotoxy(25,10);cout << "|| 2. Determinan Matriks              ||";
        gotoxy(25,11);cout << "|| 3. Matriks Adjoin                  ||";
        gotoxy(25,12);cout << "|| 4. Inverse Matriks                 ||";
        gotoxy(25,13);cout << "|| 5. Keluar                          ||";
        gotoxy(25,14);cout << "||                                    ||";
        gotoxy(25,15);cout << "||                                    ||";
        gotoxy(25,16);cout << "[]====================================[]";
        gotoxy(25,17);cout << "||                                    ||";
        gotoxy(25,18);cout << "||    Choose the Menu [ 1-5 ]         ||";
        gotoxy(25,19);cout << "||                                    ||";
        gotoxy(25,20);cout << "||                                    ||";
        gotoxy(25,21);cout << "[]====================================[]";
        gotoxy(25,20);cout << "||                                    ||";gotoxy(39,19);cin >> pilih;
        switch(pilih)
        {
            case 1:{//OPERASI
                do{
                    bersihmenu();
                    gotoxy(25,8);cout << "||         Operasi Matriks            ||";
                    gotoxy(25,9);cout << "|| 1. Penjumlahan Matriks             ||";
                    gotoxy(25,10);cout << "|| 2. Pengurangan Matriks             ||";
                    gotoxy(25,11);cout << "|| 3. Perkalian Matriks dengan Skalar ||";
                    gotoxy(25,12);cout << "|| 4. Perkalian antar Matriks         ||";
                    gotoxy(25,13);cout << "|| 5. Transpose Matriks               ||";
                    gotoxy(25,14);cout << "|| 6. Kembali                         ||";
                    gotoxy(25,15);cout << "||                                    ||";
                    gotoxy(25,16);cout << "[]====================================[]";
                    gotoxy(25,17);cout << "||                                    ||";
                    gotoxy(25,18);cout << "||    Choose the Menu [ 1-6 ]         ||";
                    gotoxy(25,19);cout << "||                                    ||";
                    gotoxy(25,20);cout << "||                                    ||";
                    gotoxy(25,21);cout << "[]====================================[]";
                    gotoxy(25,20);cout << "||                                    ||";gotoxy(39,19);cin >> pilih;
                    if(pilih == 1){ //Penjumlahan
                        gotoxy(31,20);cout<<"Penjumlahan Matriks";
                        system("cls");
                        cout << "Operasi Penjumlahan Matriks" <<endl;
                        cout << "Input Ordo Matriks 1\n";
                        cout<<"Baris : ";cin >> baris1;
                        cout<<"Kolom : ";cin >> kolom1;
                        cout << "Input Ordo Matriks 2\n";
                        cout<<"Baris : ";cin >> baris2;
                        cout<<"Kolom : ";cin >> kolom2;

                        while(baris1 != baris2 || kolom1 != kolom2){
                            if(baris1 != baris2){
                                cout << "\nError !!\nBaris Matriks 1 dan Baris Matriks 2 Tidak Sama" << endl;
                            }
                            else if(kolom1 != kolom2){
                                cout << "\nError !!\nKolom Matriks 1 dan Kolom Matriks 2 Tidak Sama" << endl;
                            }
                            cout << "Silahkan Input Ulang"<<endl<<endl;
                        cout << "Input Ordo Matriks 1\n";
                            cout<<"Baris : ";cin >> baris1;
                            cout<<"Kolom : ";cin >> kolom1;
                        cout << "Input Ordo Matriks 2\n";
                            cout<<"Baris : ";cin >> baris2;
                            cout<<"Kolom : ";cin >> kolom2;
                        }

                        cout<<"\nInput Elemen Matriks 1\n";
                        inputMatriks(matriks1, baris1, kolom1);
                        cout<<"\nMatriks 1\n";
                        tampilMatriks(matriks1, baris1, kolom1);

                        cout<<"\nInput Elemen Matriks 2\n";
                        inputMatriks(matriks2, baris2, kolom2);
                        cout<<"\nMatriks 2\n";
                        tampilMatriks(matriks2, baris2, kolom2);

                        penjumlahan(matriks1, matriks2, hasil, baris1, kolom2);
                        cout<<"\nMatriks Hasil Penjumlahan\n";
                        tampilMatriks(hasil, baris1, kolom2);
                        cout << endl;
                        break;
                    }
                    else if(pilih==2){
                        system("cls");
                        cout << "Operasi Pengurangan Matriks" <<endl;
                        cout << "Input Ordo Matriks 1\n";
                        cout<<"Baris : ";cin >> baris1;
                        cout<<"Kolom : ";cin >> kolom1;
                        cout << "Input Ordo Matriks 2\n";
                        cout<<"Baris : ";cin >> baris2;
                        cout<<"Kolom : ";cin >> kolom2;

                        while(baris1 != baris2 || kolom1 != kolom2){
                            if(baris1 != baris2){
                                cout << "\nError !!\nBaris Matriks 1 dan Baris Matriks 2 Tidak Sama" << endl;
                            }
                            else if(kolom1 != kolom2){
                                cout << "\nError !!\nKolom Matriks 1 dan Kolom Matriks 2 Tidak Sama" << endl;
                            }
                            cout << "Silahkan Input Ulang"<<endl<<endl;
                            cout << "Input Ordo Matriks 1"<<endl;
                            cout<<"Baris : ";cin >> baris1;
                            cout<<"Kolom : ";cin >> kolom1;
                            cout << "Input Ordo Matriks 2"<<endl;
                            cout<<"Baris : ";cin >> baris2;
                            cout<<"Kolom : ";cin >> kolom2;
                        }

                        cout<<"\nInput Elemen Matriks 1\n";
                        inputMatriks(matriks1, baris1, kolom1);

                        cout<<"\nMatriks 1\n";
                        tampilMatriks(matriks1, baris1, kolom1);

                        cout<<"\nInput Elemen Matriks 2\n";
                        inputMatriks(matriks2, baris2, kolom2);

                        cout<<"\nMatriks 2\n";
                        tampilMatriks(matriks2, baris2, kolom2);

                        pengurangan(matriks1, matriks2, hasil, baris1, kolom2);
                        cout<<"\nMatriks Hasil Pengurangan\n";
                        tampilMatriks(hasil, baris1, kolom2);
                        cout << endl;
                        break;
                    }
                    else if(pilih==3){
                        system("cls");
                        cout << "Perkalian Matriks dengan Skalar"<< endl;
                        cout << "Masukkan Baris dan Kolom Matriks\n";
                        cout<<"Baris : ";cin >> baris1;
                        cout<<"Kolom : ";cin >> kolom1;

                        cout<<"\nInput Elemen Matriks\n";
                        inputMatriks(matriks1, baris1, kolom1);
                        cout<<"\nMatriks "<<baris1<<"x"<<kolom1<<endl;
                        tampilMatriks(matriks1, baris1, kolom1);

                        cout << "Masukkan Skalar : ";cin >> skalar;
                        perkalianSkalar(matriks1,hasil,baris1,kolom1,skalar);
                        cout<<"\nMatriks Hasil Perkalian\n";
                        tampilMatriks(hasil, baris1, kolom1);
                        cout << endl;

                        break;
                    }
                    else if(pilih==4){
                        system("cls");
                        cout << "Perkalian antar Matriks"<< endl;
                        cout << "Input Ordo Matriks 1\n";
                        cout<<"Baris : ";cin >> baris1;
                        cout<<"Kolom : ";cin >> kolom1;
                        cout << "Input Ordo Matriks 2\n";
                        cout<<"Baris : ";cin >> baris2;
                        cout<<"Kolom : ";cin >> kolom2;

                        while(kolom1 != baris2){
                            cout << "\nError, Kolom matriks 1 tidak sama dengan Baris Matriks 2" << endl;
                            cout << "Silahkan Input Ulang"<<endl<<endl;
                            cout << "Input Ordo Matriks 1"<<endl;
                            cout<<"Baris : ";cin >> baris1;
                            cout<<"Kolom : ";cin >> kolom1;
                            cout << "Input Ordo Matriks 2"<<endl;
                            cout<<"Baris : ";cin >> baris2;
                            cout<<"Kolom : ";cin >> kolom2;
                        }

                        cout<<"\nInput Elemen Matriks 1\n";
                        inputMatriks(matriks1, baris1, kolom1);

                        cout<<"\nMatriks 1\n";
                        tampilMatriks(matriks1, baris1, kolom1);

                        cout<<"\nInput Elemen Matriks 2\n";
                        inputMatriks(matriks2, baris2, kolom2);

                        cout<<"\nMatriks 2\n";
                        tampilMatriks(matriks2, baris2, kolom2);

                        perkalian(matriks1, matriks2, hasil, baris1, kolom1, baris2, kolom2);
                        cout<<"\nMatriks Hasil Perkalian\n";
                        tampilMatriks(hasil, baris1, kolom2);
                        cout << endl;
                        break;
                    }
                    else if(pilih==5){
                        system("cls");
                        cout << "Transpose Matriks" <<endl;
                        cout << "Masukkan Baris dan Kolom Matriks\n";
                        cout<<"Baris : ";cin >> baris1;
                        cout<<"Kolom : ";cin >> kolom1;
                        cout << "\nInput Elemen Matriks" <<endl;
                        inputMatriks(matriks1, baris1, kolom1);
                        cout<<"\nMatriks "<<baris1<<"x"<<kolom1<<endl;
                        tampilMatriks(matriks1, baris1, kolom1);
                        transpose(matriks1, hasil, baris1, kolom1);
                        cout<<"\nMatriks Transpose"<<endl;
                        tampilMatriks(hasil, kolom1, baris1);

                        cout<<endl<<endl;
                        break;
                    }
                    else if(pilih==6){
                        gotoxy(33,20);cout<<"Press any to back..";
                        break;
                    }
                    else{
                        gotoxy(31,20);cout<<"Pilihan tidak tersedia";
                        break;
                    }
                }while(pilih!=999);
                break;
            }
            case 2:{//DETERMINAN
                do{
                    bersihmenu();
                    gotoxy(25,8);cout << "||         Determinan Matriks         ||";
                    gotoxy(25,9);cout << "|| 1. Determinan 2x2                  ||";
                    gotoxy(25,10);cout << "|| 2. Determinan 3x3                  ||";
                    gotoxy(25,11);cout << "|| 3. Kembali                         ||";
                    gotoxy(25,12);cout << "||                                    ||";
                    gotoxy(25,13);cout << "||                                    ||";
                    gotoxy(25,14);cout << "||                                    ||";
                    gotoxy(25,15);cout << "||                                    ||";
                    gotoxy(25,16);cout << "[]====================================[]";
                    gotoxy(25,17);cout << "||                                    ||";
                    gotoxy(25,18);cout << "||    Choose the Menu [ 1-3 ]         ||";
                    gotoxy(25,19);cout << "||                                    ||";
                    gotoxy(25,20);cout << "||                                    ||";
                    gotoxy(25,21);cout << "[]====================================[]";
                    gotoxy(25,20);cout << "||                                    ||";gotoxy(39,19);cin >> pilih;
                    if(pilih == 1){//determinan 2x2
                        system("cls");
                        cout << "Determinan Matriks 2x2" <<endl;
                        cout << "Input Elemen Matriks 2x2" <<endl;
                        inputMatriks(matriks1, 2, 2);
                        cout << "\nMatriks 2x2" <<endl;
                        tampilMatriks(matriks1, 2, 2);
                        cout<<"\nOperasi Determinan Matriks 2x2 "<<endl;
                        det = det22(matriks1);
                        operasiDeterminan22(matriks1, det);

                        cout<<endl<<endl;
                        break;
                    }
                    else if(pilih==2){//determinan 3x3
                        system("cls");
                        cout << "Determinan Matriks 3x3" <<endl;
                        cout << "Input Elemen Matriks 3x3" <<endl;
                        inputMatriks(matriks1, 3, 3);
                        cout << "\nMatriks 3x3" <<endl;
                        tampilMatriks(matriks1, 3, 3);
                        cout<<"\nOperasi Determinan Matriks 3x3 "<<endl;
                        det = det33(matriks1);
                        operasiDeterminan33(matriks1, det);
                        cout<<endl<<endl;
                        break;
                    }
                    else if(pilih==3){
                        gotoxy(31,20);cout<<"Press any to back..";
                        break;
                    }
                    else{
                        gotoxy(31,20);cout<<"Pilihan tidak tersedia!";
                        break;
                    }
                }while(pilih!=999);
                break;
            }
            case 3:{ //ADJOIN

                    bersihmenu();
                    gotoxy(25,8);cout << "||         Adjoin Matriks             ||";
                    gotoxy(25,9);cout << "|| 1. Adjoin 2x2                      ||";
                    gotoxy(25,10);cout << "|| 2. Adjoin 3x3                      ||";
                    gotoxy(25,11);cout << "|| 3. Kembali                         ||";
                    gotoxy(25,12);cout << "||                                    ||";
                    gotoxy(25,13);cout << "||                                    ||";
                    gotoxy(25,14);cout << "||                                    ||";
                    gotoxy(25,15);cout << "||                                    ||";
                    gotoxy(25,16);cout << "[]====================================[]";
                    gotoxy(25,17);cout << "||                                    ||";
                    gotoxy(25,18);cout << "||    Choose the Menu [ 1-3 ]         ||";
                    gotoxy(25,19);cout << "||                                    ||";
                    gotoxy(25,20);cout << "||                                    ||";
                    gotoxy(25,21);cout << "[]====================================[]";
                    gotoxy(25,20);cout << "||                                    ||";gotoxy(39,19);cin >> pilih;
                    if(pilih == 1){//ADJOIN 2x2
                        system("cls");
                        cout << "Adjoin Matriks 2x2" <<endl;
                        cout << "Input Elemen Matriks 2x2" <<endl;
                        inputMatriks(matriks1, 2, 2);
                        cout << "\nMatriks 2x2" <<endl;
                        tampilMatriks(matriks1, 2, 2);
                        adjoin22(matriks1, hasil);
                        cout<<endl<<endl;
                        break;
                    }
                    else if(pilih==2){//ADJOIN 3x3
                        system("cls");
                        cout << "Adjoin Matriks 3x3" <<endl;
                        cout << "Input Elemen Matriks 3x3" <<endl;
                        inputMatriks(matriks1, 3, 3);
                        cout << "\nMatriks 3x3" <<endl;
                        tampilMatriks(matriks1, 3, 3);
                        adjoin33(matriks1, hasil);
                        cout<<endl<<endl;
                        break;

                    }

                    else if(pilih==3){//ADJOIN 3x3
                        gotoxy(31,20);cout<<"Press any to back..";
                        break;

                    }
                    else{
                        gotoxy(31,20);cout<<"Pilihan tidak tersedia!";
                        break;
                    }
                }while(pilih!=999);
                break;
            case 4: { //INVERSE
                do{
                    bersihmenu();
                    gotoxy(25,8);cout << "||         Inverse Matriks            ||";
                    gotoxy(25,9);cout << "|| 1. Inverse 2x2                     ||";
                    gotoxy(25,10);cout << "|| 2. Inverse 3x3                     ||";
                    gotoxy(25,11);cout << "|| 3. Kembali                         ||";
                    gotoxy(25,12);cout << "||                                    ||";
                    gotoxy(25,13);cout << "||                                    ||";
                    gotoxy(25,14);cout << "||                                    ||";
                    gotoxy(25,15);cout << "||                                    ||";
                    gotoxy(25,16);cout << "[]====================================[]";
                    gotoxy(25,17);cout << "||                                    ||";
                    gotoxy(25,18);cout << "||    Choose the Menu [ 1-3 ]         ||";
                    gotoxy(25,19);cout << "||                                    ||";
                    gotoxy(25,20);cout << "||                                    ||";
                    gotoxy(25,21);cout << "[]====================================[]";
                    gotoxy(25,20);cout << "||                                    ||";gotoxy(39,19);cin >> pilih;
                    if(pilih==1){
                        system("cls");
                        cout << "Invers Matriks 2x2" <<endl;
                        cout << "Input Elemen Matriks 2x2" <<endl;
                        inputMatriks(matriks1, 2, 2);

                        cout << "\nMatriks 2x2" <<endl;
                        tampilMatriks(matriks1, 2, 2);

                        det=det22(matriks1);
                        operasiDeterminan22(matriks1, det);

                        cout<<endl;
                        if(det == 0){
                            cout << "\nMatriks ini tidak memiliki inverse,\nkarena Determinan = 0";
                        }else{
                            invers22(matriks1, hasil, det);
                        }
                        cout<<endl<<endl;
                        break;
                    }
                    else if(pilih==2){
                        system("cls");
                        cout << "Inverse Matriks 3x3" <<endl;
                        cout << "Input Elemen Matriks 3x3" <<endl;
                        inputMatriks(matriks1, 3, 3);

                        cout << "\nMatriks 3x3" <<endl;
                        tampilMatriks(matriks1, 3, 3);

                        det=det33(matriks1);
                        operasiDeterminan33(matriks1, det);

                        cout<<endl;
                        if(det == 0){
                            cout << "\nMatriks ini tidak memiliki inverse,\nkarena Determinan = 0";
                        }else{
                            adjoin33(matriks1, hasil);
                            invers33(hasil, det);
                        }
                        cout<<endl<<endl;
                        break;

                    }
                    else if(pilih==3){
                        gotoxy(31,20);cout<<"Press any to back..";
                        break;
                    }
                    else{
                        gotoxy(31,20);cout<<"Pilihan tidak tersedia!";
                        break;
                    }
                }while(pilih!=999);
                break;
            }
            case 5: system("cls");{
                return 0;
            }
            default : {
                gotoxy(31,20);cout<<"Pilihan tidak tersedia!";
            }
        }
        getch();
    }
    while (pilih!=999);
}
