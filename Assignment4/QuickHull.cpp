#include<bits/stdc++.h>
using namespace std;

struct Pt{
	double x, y;
};

void print_Pt(Pt p){
	cout<<p.x<<" "<<p.y<<endl;
}

int area(Pt p, Pt q, Pt r){
	return abs( p.x*(q.y-r.y) + q.x*(r.y-p.y) + r.x*(p.y-q.y) );
}

double cal_dis(Pt p, Pt q, Pt r){
	double num,den;
	num = area(p, q, r);
	return num;
}

Pt *convex_hull_set;
int h=0;
int get_sign(Pt A, Pt B, Pt X){
	int sign = (A.y-B.y)*X.x + (B.x-A.x)*X.y + (B.y*A.x-A.y*B.x);
	if(sign>0) return 1;
	if(sign<0) return -1;
	return 0;
}

void hullfind(Pt *Pt, int n, Pt A, Pt B){
	if(n<=0) return;
	int index=0, max_dis, temp_dis;
	for(int i=0;i<n;i++){
		temp_dis = cal_dis(A, B, Pt[i]);
		if(i==0) max_dis=temp_dis;
		else if(temp_dis > max_dis){
			max_dis = temp_dis;
			index = i;
		}
	}

	convex_hull_set[h++]=Pt[index];

	Pt C = Pt[index];

	Pt G;
	G.x = (A.x + B.x + C.x)/3;
	G.y = (A.y + B.y + C.y)/3;
	int sign = get_sign(A, C, G);

	Pt *Pt_pos = new Pt[n];
	Pt *Pt_neg = new Pt[n];
	int p=0, q=0;
	for(int i=0;i<n;i++){
		if(sign*get_sign(A,C,Pt[i]) < 0) Pt_pos[p++]=Pt[i];
	}
	sign = get_sign(B, C, G);
	for(int i=0;i<n;i++){
		if(sign*get_sign(B,C,Pt[i]) < 0) Pt_neg[q++]=Pt[i];
	}
	hullfind(Pt_pos, p, A, C);
	hullfind(Pt_neg, q, C, B);
}

int main(){
	int n;
	cout<<"No. of Pts= ";
	cin>>n;
	Pt *Pt = new Pt[n];
	convex_hull_set = new Pt[n];
	cout<<"Enter the description of "<<n<<" Pts:\n";
	int leftmost=0, rightmost=0;
	for(int i=0;i<n;i++){
		cin>>Pt[i].x>>Pt[i].y;
		if(Pt[i].x < Pt[leftmost].x) leftmost=i;
		if(Pt[i].x > Pt[rightmost].x) rightmost=i;
	}

	clock_t t;
	t=clock();
	Pt *Pt_pos = new Pt[n];
	Pt *Pt_neg = new Pt[n];
	int A,B,C;
	A = Pt[leftmost].y - Pt[rightmost].y;
	B = -Pt[leftmost].x + Pt[rightmost].x;
	C = Pt[rightmost].y*Pt[leftmost].x - Pt[leftmost].y*Pt[rightmost].x;
	int p=0, q=0, val;
			for(int i=0;i<n;i++){
				if(i!=leftmost && i!=rightmost){
					val = A*Pt[i].x + B*Pt[i].y + C;
					if(val>0){
						Pt_pos[p++]=Pt[i];
					}
					if(val<0){
						Pt_neg[q++]=Pt[i];
					}
				}
			}

	convex_hull_set[h++] = Pt[leftmost];
	convex_hull_set[h++] = Pt[rightmost];
	hullfind(Pt_pos, p, Pt[leftmost], Pt[rightmost]);
	hullfind(Pt_neg, q, Pt[leftmost], Pt[rightmost]);

	t=clock()-t;

	cout<<"Points in the convex hull set:\n";
	cout<<"h="<<h<<endl;
	for(int i=0;i<h;i++){
		print_Pt(convex_hull_set[i]);
	}

	printf ("It took %d clicks (%f seconds).\n",t,((float)t)/CLOCKS_PER_SEC);
	return 0;
}
