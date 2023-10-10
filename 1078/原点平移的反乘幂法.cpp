#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
using namespace std;

class Matrix
{
    public:
    vector<vector<double> > p;
    int row;
    int col;
    public:
    Matrix(){};
    Matrix(vector<vector<double> > p)
    {
        this->p = p;
        row = p.size();
        col = p[0].size();  
    }
    Matrix(int row,int col)
    {
        this->row = row;
        this->col = col;
        p.resize(row);
        for(int i = 0;i < row;i++)
            p[i].resize(col);
    }
    Matrix(int n)
    {
        this->row = n;
        this->col = n;
        p.resize(n);
        for(int i = 0;i < n;i++)
            p[i].resize(n);
    }
    Matrix(Matrix &m)
    {   this->p=m.p;
        this->row=m.row;
        this->col=m.col;
    };
    ~Matrix(){};
    
    int GetRow(){return row;}
    int GetCol(){return col;}
    double GetElem(int i,int j){return p[i - 1][j - 1];};
    void SetElem(int i,int j,double v){p[i - 1][j - 1] = v;}
    void SetI()
    {
        for(int i = 1;i <= row;i++)
            for(int j = 1;j <= col;j++)
            {
                if(i==j)
                    SetElem(i,j,1.0);
                else
                    SetElem(i,j,0.0);
            }
    }

    void resize(int r,int c)
    {
        p.resize(r);
        for(int i = 0 ; i < r ; i++)
            p[i].resize(c);
        row = r;
        col = c;
    };

    void print()
    {
         for(int i = 1;i <= row;i++)
         {
            for(int j = 1;j <= col;j++)
                cout<<setiosflags(ios::fixed)<<setprecision(6)<<GetElem(i,j)<<" ";
            cout<<endl;
         }   
    }
    friend Matrix operator+(Matrix& m1 , Matrix& m2)
    {
        Matrix tmp(m1.GetRow(),m1.GetCol());
        int r = m1.GetRow();
        int c = m1.GetCol();
        for(int i = 1;i <= r;i++)
            for(int j = 1;j <= c;j++)
                tmp.SetElem( i ,j ,m1.GetElem(i,j) + m2.GetElem(i,j));
        return tmp;   
    };
   
    friend Matrix operator-(Matrix& m1 , Matrix& m2)
    {
        Matrix tmp(m1.GetRow(),m1.GetCol());
        int r = m1.GetRow();
        int c = m1.GetCol();
        for(int i = 1;i <= r;i++)
            for(int j = 1;j <= c;j++)
                tmp.SetElem( i ,j ,m1.GetElem(i,j) - m2.GetElem(i,j));
        return tmp;   
    };

    friend Matrix operator*(Matrix& m1,Matrix& m2)
    {
        Matrix tmp(m1.GetRow(),m2.GetCol());
        for(int i = 1;i <= m1.GetRow();i++)
        {
             for(int j = 1;j <= m2.GetCol();j++)
             {
                 double sum = 0.0;
                 for(int k = 1;k <=m2.GetRow();k++)
                 {
                    sum +=(m1.GetElem(i,k)*m2.GetElem(k,j));
                 }
                 tmp.SetElem(i,j,sum);
             }
        }
        return tmp;
    };

    friend Matrix operator*(Matrix& m ,double long w)
    {
        Matrix tmp(m.GetRow(),m.GetCol());
        for(int i = 1;i <= m.GetRow();i++)
            for(int j = 1;j <= m.GetCol();j++)
                tmp.SetElem( i ,j ,m.GetElem(i,j) * w);
        return tmp; 
    };
    friend Matrix operator/(Matrix& m ,double long w)
    {
        Matrix tmp(m.GetRow(),m.GetCol());
        for(int i = 1;i <= m.GetRow();i++)
            for(int j = 1;j <= m.GetCol();j++)
                tmp.SetElem( i ,j ,m.GetElem(i,j)/w);
        return tmp; 
    };
    

    friend Matrix inverse(Matrix m)
    {
      Matrix tmp(m.GetRow(),m.GetCol());
      int r = tmp.GetRow();
      int c = tmp.GetCol();
      tmp.SetI();
      for (int i = 1; i <= r; i++)
	  {
		for (int j = i + 1; j <= c; j++)
		{
			double ind1 = double(m(j,i)) / double(m(i,i));
			if (m(j,i) == m(i,i))
				ind1 = 1;
			for (int k = 1; k <= c; k++)
			{
				m.SetElem(j,k,(m(j,k) - ind1 * m(i,k)));
                tmp.SetElem(j,k,(tmp(j,k) - ind1 * tmp(i,k)));

			}
		}
	 }
     for (int i = r ; i >= 1; i--)
	{
		for (int j = i - 1; j >= 1; j--)
		{
			double ind2 = m(j,i) / m(i,i);
			if (m(j,i) == m(i,i))
			{
				ind2 = 1;
			}
			for (int k = 1; k <= c; k++)
			{
				m.SetElem(j,k,(m(j,k) - ind2 * m(i,k)));
                tmp.SetElem(j,k,(tmp(j,k) - ind2 * tmp(i,k)));
			}
		}
	}
    for(int i = 1;i <=r;i++)
    {
        double ind3 = m(i,i);
        m.SetElem(i,i,m(i,i)/ind3);
        for(int j = 1;j <=c;j++)
            tmp.SetElem(i,j,tmp(i,j)/ind3);
    }
    return tmp;
    }; 
    double operator()(int i,int j){return p[i - 1][j - 1];}
    friend Matrix transpose(Matrix m)
    {
        int r = m.GetRow();
        int c = m.GetCol();
        Matrix tmp;
        tmp.resize(c,r);
        for(int i = 1;i <=c;i++)
        {
            for(int j = 1;j <=r;j++)
                tmp.SetElem(i,j,m(j,i));
        }
        return tmp;
    }
    double convert_to_scalar()
    {
        return p[0][0];
    }

    friend Matrix CholeskyFactorization(Matrix m)
    {
       Matrix tmp;
       int r = m.GetCol();
       int c = m.GetRow();
       tmp.resize(r,c);
       for(int j = 1;j <= r;j++)
        {
        double t = 0.0;
        for(int k = 1;k < j;k++)
            t += (tmp(j,k)*tmp(j,k));
         tmp.SetElem(j,j,sqrt(m(j,j) - t));
        for(int i = j + 1; i <= c;i++)
        {   
            double sum = 0.0;
            for(int k = 1;k < j;k++)
                sum += (tmp(i,k)*tmp(j,k));
            tmp.SetElem(i,j,(m(i,j) - sum)/tmp(j,j));
        }
        }
        return tmp;
    }
    friend double innerproduct(Matrix x,Matrix y)
    {
        int n = x.GetCol();
        double sum = 0.0;
        for(int i = 1;i<=n;i++)
        {
            sum +=x(1,i)*y(i,1); 
        }
        return sum;
    }
    
};
double norm(Matrix x,Matrix y)
{
    double sum=0.0;
    int r = x.GetRow();
    int c = x.GetCol();
    for(int i = 1;i <=r;i++)
    {
        for(int j = 1;j <= c;j++)
            sum += ((x(i,j) - y(i,j)) *(x(i,j) - y(i,j)));
    }
    return sqrt(sum);
}
double norm(Matrix x)
{
    double sum=0.0;
    int r = x.GetRow();
    int c = x.GetCol();
    for(int i = 1;i <=r;i++)
    {
        for(int j = 1;j <= c;j++)
            sum += (x(i,j) * x(i,j));
    }
    return sqrt(sum);
}
int foundmax(Matrix x)
{
    int rank = 1;
    double Max = fabs(x.GetElem(rank,1));
    for(int i = 1;i <=x.GetRow();i++)
        rank = (fabs(x.GetElem(i,1)) > Max)?i:rank;
    return rank;
}

int main()
{
    int n;
    cin >> n;
    //Matrix A({{2,-1,0},{0,2,-1},{0,-1,2}});
    vector<vector<double> > a;
    vector<vector<double> > X;
    a.resize(n);
    for(int i = 0;i < n;i++)
        a[i].resize(n);
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < n;j++)
        {
            double t;
            cin >> t;
            a[i][j] = t;
        }
    }
    X.resize(n);
    for(int i = 0;i < n;i++)
        X[i].resize(1);
    for(int i = 0;i < n;i++)
    {
        double t;
        cin >> t;
        X[i][0] = t;
    }
    Matrix A(a);
    Matrix x(X);
    //Matrix x({{0},{0},{1}});
    double lamda ;
    cin >> lamda;
    //double lamda = 2.93;
    int Na;
    cin >> Na;
    Matrix I(n);
    I.SetI();
    I = I * lamda;
    Matrix M;
    M = A - I;
    Matrix N;
    N = inverse(M);
    double tol;
    cin >> tol;
    double u = 1.0;
    int k = 1;
    double beta;
    int r = foundmax(x);
    double alpha = x.GetElem(r,1);
    while(k < Na)
    {
        int r = foundmax(x);
        double alpha = x.GetElem(r,1);
        Matrix y;
        y = x / alpha;
        x = N * y;
        double beta = x.GetElem(r,1);
        r = foundmax(x);
        alpha = x.GetElem(r,1);
        Matrix t;
        t = transpose(x);
        t = t / alpha;
        if(fabs((1/beta)-(1/u))<=tol)
        {
            lamda = lamda + (1/beta);
            cout<<setiosflags(ios::fixed)<<setprecision(6)<<lamda<<endl;
            t.print();
            break;
        }
        else
        {
            k = k + 1;
            u = beta;
        }
    }
    
    return 0;    
}

