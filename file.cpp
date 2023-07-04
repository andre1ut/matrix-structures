#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>

using namespace std;

ifstream ci("proiect.in");

struct ma{
    int mat[100][100];
    int n;
    int m;
};

void afisare_sin(int mat[100][100],int n,int m)
{
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cout<<mat[i][j]<<" ";

        cout<<endl;
    }
}

void citire(ma v[10]){
  for(int i=0;i<10;i++){
        ci>>v[i].n>>v[i].m;
    for(int x=0;x<v[i].n;x++)
      for(int y=0;y<v[i].m;y++)
        ci>>v[i].mat[x][y];
  }
}

void afisare(ma v[10]){
    cout<<"Ce matrice doriti sa afisam?"<<endl;
    cout<<"1)O matrice"<<endl;
    cout<<"2)Toate matricele"<<endl;

    int x; cin>>x;
    system("cls");
    switch(x){

    case 1:
        cout<<"Ce matrice doriti sa va afisez pe ecran?"<<endl;
        cout<<"Introduceti un numar de la 0 la 9:";
        int z;cin>>z;
        if(z<0 || z>9){
            cout<<"Imi pare rau, dar numarul pe care l-ai introdus nu corespunde unei matrice citite in memorie :("<<endl;
            break;
        }
        cout<<v[z].n<<" "<<v[z].m<<endl;
        for(int x=0;x<v[z].n;x++){
            for(int y=0;y<v[z].m;y++){
                cout<<v[z].mat[x][y]<<" ";
            }
            cout<<endl;
        }
        break;

    case 2:
        for(int i=0;i<10;i++){

            cout<<v[i].n<<" "<<v[i].m<<endl;
            for(int x=0;x<v[i].n;x++){
            for(int y=0;y<v[i].m;y++){
                cout<<v[i].mat[x][y]<<" ";
                }
            cout<<endl;
            }
            cout<<endl;
        }
        break;
    }
}

void dimensiuni(ma v[10]){
    cout<<"Carei matrice doriti sa ii aflati dimensiunile?"<<endl;
    cout<<"Introduceti o cifra de la 0 la 9: "<< endl;
    int x;cin>>x;
    if(x<0 || x>9) cout<<"Imi pare rau, dar numarul pe care l-ai introdus nu corespunde unei matrice citite in memorie :("<<endl;
    else{
        cout<<"Matricea "<<x<<" are "<<v[x].n<<" linii si "<<v[x].m<<" coloane"<<endl;
        cout<<endl;
        for(int i=0;i<v[x].n;i++){
            for(int j=0;j<v[x].m;j++){
                cout<<v[x].mat[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
}

void rotire_90(int mat[100][100], int rows, int columns, int key, ma v[10])
{
    int aux[100][100];

    for(int i=0;i<columns;i++){
        for(int j=0;j<rows;j++){
            aux[i][j]=mat[rows-1-j][i];
        }
    }

    for(int i=0;i<columns;i++){
        for(int j=0;j<rows;j++){
            mat[i][j]=aux[i][j];
        }
    }
}

void rotire(ma v[10]){
    cout<<"Ce matrice vreti sa rotim?"<<endl;
    cout<<"Introduceti un numar de la 0 la 9: ";
    int a;
    cin>>a;
    if(a<0 || a>9){
        system("cls");
        cout<<"Imi pare rau, dar numarul pe care l-ai introdus nu corespunde unei matrice citite in memorie :("<<endl;
    }
    else{
        system("cls");
        cout<<"Cu cate grade vreti sa o rotim?"<<endl;
        cout<<"Introduceti un numar dintre urmatoarele: 90, 180, 270: ";
        int b;
        cin>>b;
        if(b!=90 && b!=180 && b!=270){
         system("cls");
         cout<<"Imi pare rau, numarul introdus este unul prea greu pentru mine :("<<endl;
        }
        else{
            b/=90;

            switch(b)
            {
            case 1:
                int aux[100][100];

                for(int i=0;i<v[a].n;i++){
                    for(int j=0;j<v[a].m;j++)
                        aux[i][j]=v[a].mat[i][j];
                }

                rotire_90(aux,v[a].n,v[a].m,a,v);
                cout<<endl;
                for(int i=0;i<v[a].m;i++){
                    for(int j=0;j<v[a].n;j++)
                        cout<<aux[i][j]<<" ";

                    cout<<endl;
                }
                break;

            case 2:
                int aux1[100][100];

                for(int i=0;i<v[a].n;i++){
                    for(int j=0;j<v[a].m;j++)
                        aux1[i][j]=v[a].mat[i][j];
                }

                rotire_90(aux1,v[a].n,v[a].m,a,v);
                rotire_90(aux1,v[a].m,v[a].n,a,v);
                cout<<endl;
                for(int i=0;i<v[a].n;i++){
                    for(int j=0;j<v[a].m;j++)
                        cout<<aux1[i][j]<<" ";

                    cout<<endl;
                }
                break;

            case 3:
                int aux2[100][100];

                for(int i=0;i<v[a].n;i++){
                    for(int j=0;j<v[a].m;j++)
                        aux2[i][j]=v[a].mat[i][j];
                }
                rotire_90(aux2,v[a].n,v[a].m,a,v);
                rotire_90(aux2,v[a].m,v[a].n,a,v);
                rotire_90(aux2,v[a].n,v[a].m,a,v);
                cout<<endl;
                for(int i=0;i<v[a].m;i++){
                    for(int j=0;j<v[a].n;j++)
                        cout<<aux2[i][j]<<" ";

                    cout<<endl;
                }
                break;
            }
        }
    }
}

void matrix_multiply(int matrix1[100][100], int matrix2[100][100], int result[100][100], int m, int n, int p) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            double sum = 0;
            for (int k = 0; k < n; k++) {
                sum += matrix1[i][k] * matrix2[k][j];
            }
            result[i][j] = sum;
        }
    }
}

void sortare_matrice(ma v[10])
{
    int a=0,sum=0,sum1=0;

    for(int c=0;c<9;c++){
        while(a!=9){
            
            for(int i=0;i<v[a].n;i++)
                for(int j=0;j<v[a].m;j++)
                    sum+=v[a].mat[i][j];
            
            for(int i=0;i<v[a+1].n;i++)
                for(int j=0;j<v[a+1].m;j++)
                    sum1+=v[a+1].mat[i][j];

            if(sum>sum1){
                swap(v[a],v[a+1]);
                a++;
            }
            else{
                a++;
            }
            sum=sum1=0;
        }
        a=0;
    }
    cout<<"Matricele au fost sortate in vectorul de provenienta"<<endl;
    cout<<"Doriti sa le afisam in ordine?"<<endl;
    cout<<"1)DA"<<endl;
    cout<<"2)NU"<<endl;
    cout<<"Introduceti unul dintre numerele prezentate: ";
    int z;cin>>z;
    if(z!=1 && z!=2){
            system("cls");
        cout<<"Varianta aleasa este inexistenta :("<<endl;
    }
    else if(z==1){
        system("cls");
        for(int x=0;x<10;x++){

            cout<<v[x].n<<" "<<v[x].m<<endl;
            for(int i=0;i<v[x].n;i++){
                for(int j=0;j<v[x].m;j++){
                    cout<<v[x].mat[i][j]<<" ";
                }
                cout<<endl;
            }
            cout<<endl;
        }
    }
    if(z==2) system("cls");
}

int main()
{
  ma v[10];
  ma matOne;
  ma matTwo;
  ma matThree;
  ma matFour;
  ma matFive;
  ma matSix;
  ma matSeven;
  ma matEight;
  ma matNine;
  ma matTen;

  v[0]=matOne;
  v[1]=matTwo;
  v[2]=matThree;
  v[3]=matFour;
  v[4]=matFive;
  v[5]=matSix;
  v[6]=matSeven;
  v[7]=matEight;
  v[8]=matNine;
  v[9]=matTen;

  citire(v);

  while(true){
    system("cls");
    cout<<"1) Afisare matrice"<<endl;
    cout<<"2) Afisare dimensiuni matrice"<<endl;
    cout<<"3) Inmultire 2 matrice"<<endl;
    cout<<"4) Sortare matrice in vector dupa criteriul sumei"<<endl;
    cout<<"5) Rotire matrice cu 90/180/270 grade"<<endl;
    cout<<"6) iesire"<<endl;

  int x;cin>>x;

  switch(x){
    case 1:
      system("cls");
      afisare(v);
      system("pause");
      break;

    case 2:
      system("cls");
      dimensiuni(v);
      system("pause");
      break;

    case 3:
        system("cls");
        cout<<"Ce matrice sa inmultim?"<<endl;
        cout<<"Introduceti doua numere de la 0 la 9, separate de un spatiu: ";
        int a,b;
        cin>>a>>b;
        if((a<0 || a>9) || (b<0 || b>9)){
            system("cls");
            cout<<"Imi pare rau dar numerle introduse nu corespund unor matrice existente :("<<endl;
            system("pause");
            break;
        }
        else{
            int aux[100][100];
            matrix_multiply(v[a].mat, v[b].mat, aux,  v[a].n,  v[a].m,  v[b].m);

            for(int i=0;i<v[a].m;i++){
                for(int j=0;j<v[b].m;j++)
                    cout<<aux[i][j]<<" ";

                cout<<endl;
            }
            system("pause");
            break;
        }

    case 4:
      system("cls");
      sortare_matrice(v);
      system("pause");
      break;

    case 5:
      system("cls");
      rotire(v);
      system("pause");
      break;

    case 6:
        return 0;
    }
  }
}