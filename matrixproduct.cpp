//Name: Aditya Bharadwaj
//SID: 013533260
//GID: 7
#include<iostream>
#include<fstream>
using namespace std;
int main(int argc, char* argv[]) {
 
const int M1_ROWS = 10000 , M1_COLS = 10000, M2_ROWS = 10000, M2_COLS = 10000;
 static int a[M1_ROWS][M1_COLS], b[M2_ROWS][M2_COLS],P_Mat[M1_ROWS][M2_COLS]={};
 ifstream f1, f2; 
 ofstream fout;
 f1.open(argv[2]);
 if(f1.fail()) {
    cerr<<"File opening failed"<<endl;
    exit(1);
    }
 
int rows1=0, cols1=0, n1=0, numTotal1=0;
 while(f1.peek()!='\n' && f1>>n1)
  ++numTotal1;
 cols1=numTotal1;
 while(f1>>n1)
  ++numTotal1;
 rows1=numTotal1/cols1;
 f1.clear();
 f1.seekg(0,ios::beg);
 while(!f1.eof()) 
    for(int i=0;i<rows1;i++) 
      for(int j=0;j<cols1;j++)         
         f1>>a[i][j];
     
 f1.close();
 
 f2.open(argv[4]);
 if(f2.fail()) {
     cerr<<"File opening failed"<<endl;
     exit(1);
     }
int rows2=0, cols2=0, n2=0, numTotal2=0;
 while(f2.peek()!='\n' && f2>>n2)
  ++numTotal2;
 cols2=numTotal2;
 while(f2>>n2)
  ++numTotal2;
 rows2=numTotal2/cols2;
 f2.clear();
 f2.seekg(0,ios::beg);

 while(!f2.eof()) 
      for(int i=0;i<rows2;i++)
        for(int j=0;j<cols2;j++)
           f2>>b[i][j];         
           

 f2.close();
if(cols1==rows2) 
{
 for(int i=0; i<rows1;i++)
  for(int j=0; j<cols2;j++)
   for(int k=0;k<cols1;k++)  
     P_Mat[i][j] += a[i][k]*b[k][j];

  for(int i=0;i<rows1;i++) {
   for(int j=0;j<cols2;j++)
    cout<<P_Mat[i][j]<<" ";
  cout<<endl;
  }
 }
else
  cerr<<"Matrix dimensions not compatible for multiplication"<<endl;  
 return 0;
}





  
