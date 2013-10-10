//
//  main.cpp
//  Numerical Process
//
//  Created by Ryo EGAMI on 2013/09/02.
//  Copyright (c) 2013年 Ryo EGAMI. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <math.h>
#include <string>
#include <iosfwd>
#include <iomanip>
#include <cmath>
#include "Numerical.h"

using namespace std;

#define FILENAME    "data3d_mrOHMICHI.dat" // データ入力
#define DOMAIN1 "result1.dat" //処理結果出力
#define DOMAIN2 "result2.dat" //処理結果出力
#define DOMAIN3 "result3.dat" //処理結果出力
#define DOMAIN4 "result4.dat" //処理結果出力
#define DOMAIN5 "result5.dat" //処理結果出力


double x[170][170][170];
double y[170][170][170];
double z[170][170][170];

double u[170][170][170];
double v[170][170][170];
double w[170][170][170];

double p[170][170][170];
double rho[170][170][170];
double t[170][170][170];

double xout[170][170][170];
double yout[170][170][170];
double zout[170][170][170];


double uout[170][170][170];
double vout[170][170][170];
double wout[170][170][170];

double pout[170][170][170];
double rhoout[170][170][170];
double tout[170][170][170];

//
//	3次元配列を確保する関数
//
/*
template <typename X> X*** Array3D( int nx, int ny ,int nz)
try{
    X*** = new int**[nx];
	//ptr[0]	= new X [nx * ny];
    ptr[0][0]	= new X [nx * ny * nz];
    for( int i=1; i<nx; i++ ){
		ptr[i]	= &(ptr[0][i*ny]);
        for (int j=1; j <ny; j++) {
            ptr[i][j] = &(ptr[0][0][j*nz]);
        }
    }
    
	return ptr;
}catch(bad_alloc){
    cout << "";
    }

//
//	2次元配列を解放する関数
//
template <typename X> void DeleteArray( X*** ptr )
{
	if( ptr[0][0] )
		delete [] ptr[0][0];
	delete [] ptr;
}

*/
int main(int argc, const char * argv[])
{
    string dum1, dum2;
    string c, cc[20], cnx, cny, cnz;
    //char chara[20];
    int i, j, k;
    int inum, jnum, knum;
    int imax, jmax, kmax;
    int nx, ny,nz;
    int id1, jd1, kd1;
    int id2, jd2, kd2;
    int id3, jd3, kd3;
    int id4, jd4, kd4;
    int id5, jd5, kd5;
    
    ifstream fin( FILENAME);

    ofstream fout1(DOMAIN1);
    ofstream fout2(DOMAIN2);
    ofstream fout3(DOMAIN3);
    ofstream fout4(DOMAIN4);
    ofstream fout5(DOMAIN5);
    
    
    //ファイルが開けなかったときの操作。
    if(fin.fail()){  // if(!fin)でもよい。
        cout << "入力ファイルをオープンできません" << endl;
        return 1;
    }
    if(fout1.fail()){  // if(!fout)でもよい。
        cout << "出力ファイルをオープンできません" << endl;
        return 1;
    }
    cout << "配列に入力しない行を読み込む" << endl;
    getline(fin, dum1);
    getline(fin, dum2);
   // getline(fin, dum);
    
    /*
    istringstream is(dum);
    is >> c >> c >> cnx;
    istringstream iss(cnx);
    for (i=1; i<=3; i++) {
        ;
    }
    iss >> nx;
    for (i=1; i<=3; i++) {
        iss >> c;
    }
    iss >> ny;
    for (i=1; i<=3; i++) {
        iss >> c;
    }
    iss >> nz;
    cout << nx << endl;
    */
    //fin >> dum >> nx >> ny >> nz >> dum;
    //cout << nx << "\t" << ny << "\t" << nz << endl;
    /*for (int i = 1; i <= 2; i++){
        cout << i << "回目：";
        cin >> name;
        cout << i << "：" << name << endl;
    }*/
    //while((fin >> x[i] >> y[i] >> z[i] >> u[i] >> v[i] >> w[i] >> p[i] >> rho[i] >> t[i])!=0){
    //    i++;
    //}
    nx = 161;
    ny = 121;
    nz = 161;
    
    /*
    // 3次元配列を動的に確保
    double ***x, ***y, ***z;
    double ***u, ***v, ***w;
    double ***p, ***rho, ***t;
    
    x = Array3D<double>(nx, ny, nz);
    y = Array3D<double>(nx, ny, nz);
    z = Array3D<double>(nx, ny, nz);
    
    u = Array3D<double>(nx, ny, nz);
    v = Array3D<double>(nx, ny, nz);
    w = Array3D<double>(nx, ny, nz);

    p   = Array3D<double>(nx, ny, nz);
    rho = Array3D<double>(nx, ny, nz);
    t   = Array3D<double>(nx, ny, nz);
    */
    
    //物体外部の格子点数をカウントする
    inum = 0;
    jnum = 0;
    knum = 0;
    
    id1 = 0;
    id2 = 0;
    id3 = 0;
    id4 = 0;
    id5 = 0;
    
    jd1 = 0;
    jd2 = 0;
    jd3 = 0;
    jd4 = 0;
    jd5 = 0;
    
    kd1 = 0;
    kd2 = 0;
    kd3 = 0;
    kd4 = 0;
    kd5 = 0;

    cout << "Now, file_reading" << endl;
        for (k = 1; k <= nz; k++) {
        for (j = 1; j <= ny; j++) {
            for (i = 1; i<= nx; i++) {
                fin >> x[i][j][k] >> y[i][j][k] >> z[i][j][k] >> u[i][j][k] >> v[i][j][k] >> w[i][j][k] >> p[i][j][k] >> rho[i][j][k] >> t[i][j][k];
            }
        }
        }
             /*   if (x[i][j][k] > 0.3 && x[i][j][k] < 1.3 && y[i][j][k] < 2.5 && z[i][j][k] > -0.025 && z[i][j][k] < 0.025) {
                    inum++;
                    jnum++;
                    knum++;
                    fout << xout[inum][jnum][knum] <<" " << yout[inum][jnum][knum] << " " << zout[inum][jnum][knum] << " " << uout[inum][jnum][knum] <<" " << vout[inum][jnum][knum] <<" " << wout[inum][jnum][knum] <<" " << pout[inum][jnum][knum] <<" " << rhoout[inum][jnum][knum] <<" " << tout[inum][jnum][knum] <<  endl;
              
                    xout[inum][jnum][knum] = x[i][j][k];
                    yout[inum][jnum][knum] = y[i][j][k];
                    zout[inum][jnum][knum] = z[i][j][k];

                    uout[inum][jnum][knum] = u[i][j][k];
                    vout[inum][jnum][knum] = v[i][j][k];
                    wout[inum][jnum][knum] = w[i][j][k];

                    pout[inum][jnum][knum] = p[i][j][k];
                    rhoout[inum][jnum][knum] = rho[i][j][k];
                    tout[inum][jnum][knum] = t[i][j][k];
  
                } */
    cout << "Now, file_sorting" << endl;
    for (k = 1; k <= nz; k++) {
        for (j = 1; j <= ny; j++) {
            for (i = 1; i<= nx; i++) {
                fin >> x[i][j][k] >> y[i][j][k] >> z[i][j][k] >> u[i][j][k] >> v[i][j][k] >> w[i][j][k] >> p[i][j][k] >> rho[i][j][k] >> t[i][j][k];
                while (<#condition#>) {
                    <#statements#>
                }
            }
        }
    }
    

                if (x[i][j][k] < 0.3 ) {
                    fout1 << x[i][j][k] <<" " << y[i][j][k] <<" " << z[i][j][k] <<" " << u[i][j][k] <<" " << v[i][j][k] <<" " << w[i][j][k] <<" " << p[i][j][k] <<" " << rho[i][j][k] <<" " << t[i][j][k] << endl;
                    id1++;
                    jd1++;
                    kd1++;
                }
                if (x[i][j][k] >= 0.3 && x[i][j][k] <= 1.3 && 0.025 <= z[i][j][k] && 1.0 >= z[i][j][k]) {
                    fout2 << x[i][j][k] <<" " << y[i][j][k] <<" " << z[i][j][k] <<" " << u[i][j][k] <<" " << v[i][j][k] <<" " << w[i][j][k] <<" " << p[i][j][k] <<" " << rho[i][j][k] <<" " << t[i][j][k] << endl;
                    id2++;
                    jd2++;
                    kd2++;
                }
                if (x[i][j][k] >= 0.3 && x[i][j][k] <= 1.3 && y[i][j][k] >= 2.5 && y[i][j][k] <= 6.5 && z[i][j][k] >= -0.025 && z[i][j][k] <= 0.025) {
                        fout3 << x[i][j][k] <<" " << y[i][j][k] <<" " << z[i][j][k] <<" " << u[i][j][k] <<" " << v[i][j][k] <<" " << w[i][j][k] <<" " << p[i][j][k] <<" " << rho[i][j][k] <<" " << t[i][j][k] << endl;
                    id3++;
                    jd3++;
                    kd3++;
                }
                if (x[i][j][k] >= 0.3 && x[i][j][k] <= 1.3 && z[i][j][k] >= -1.0 && z[i][j][k] <= -0.025) {
                        fout4 << x[i][j][k] <<" " << y[i][j][k] <<" " << z[i][j][k] <<" " << u[i][j][k] <<" " << v[i][j][k] <<" " << w[i][j][k] <<" " << p[i][j][k] <<" " << rho[i][j][k] <<" " << t[i][j][k] << endl;
                    id4++;
                    jd4++;
                    kd4++;
                }
                if (x[i][j][k] > 1.3 ) {
                        fout5 << x[i][j][k] <<" " << y[i][j][k] <<" " << z[i][j][k] <<" " << u[i][j][k] <<" " << v[i][j][k] <<" " << w[i][j][k] <<" " << p[i][j][k] <<" " << rho[i][j][k] <<" " << t[i][j][k] << endl;
                    id5++;
                    jd5++;
                    kd5++;
                            }
                        }
                    }
                }

    imax = inum;
    jmax = jnum;
    kmax = knum;
    
/*
    for (knum =1; knum <= kmax; knum++) {
        for (jnum = 1; jnum <= jmax; jnum++) {
            for (inum = 1; inum <= imax; inum++) {
 */
    /*
for (k = 1; k <= nz; k++) {
    for (j = 1; j <= ny; j++) {
        for (i = 1; i<= nx; i++) {
                fout << xout[i][j][k] <<" " << yout[inum][jnum][knum] << " " << zout[inum][jnum][knum] << " " << uout[inum][jnum][knum] <<" " << vout[inum][jnum][knum] <<" " << wout[inum][jnum][knum] <<" " << pout[inum][jnum][knum] <<" " << rhoout[inum][jnum][knum] <<" " << tout[inum][jnum][knum] <<  endl;
            }
        }
    }
    */
    cout << "domain1" << "i=" << id1 << "\t" << "j=" << jd1 << "\t" << "k=" << kd1 << endl;
    cout << "domain2" << "i=" << id2 << "\t" << "j=" << jd2 << "\t" << "k=" << kd2 << endl;
    cout << "domain3" << "i=" << id3 << "\t" << "j=" << jd3 << "\t" << "k=" << kd3 << endl;
    cout << "domain4" << "i=" << id4 << "\t" << "j=" << jd4 << "\t" << "k=" << kd4 << endl;
    cout << "domain5" << "i=" << id5 << "\t" << "j=" << jd5 << "\t" << "k=" << kd5 << endl;
    return 0;
    /*
    DeleteArray( x );
	DeleteArray( y );
	DeleteArray( z );
	DeleteArray( u );
    DeleteArray( v );
	DeleteArray( w );
	DeleteArray( p );
	DeleteArray( rho );
	DeleteArray( t );
     */
}

