#include<iostream>
using namespace std;

struct nod{
  int nr;
  nod* leg;
};
nod* v,*sf;
int n;

int Pune(nod*& v,nod*& sf,int n){
  nod* c;
  if (!v){
    v=new nod;
    v->nr=n;
    v->leg=0;
    sf=v;
  } else {
    c=new nod;
    sf->leg=c;
    c->nr=n;
    c->leg=0;
    sf=c;
  }
}

int Scoate(nod*& v){
  nod* c;
  if (!v) cout<<"Coada este vida!";
  else {
    cout<<"Am scos "<<v->nr<<endl;
    c=v;
    v=v->leg;
    delete c;
  }
}

int listare(nod* v){
  nod* c=v;
  while (c){
    cout<<c->nr<<" ";
    c=c->leg;
  }
  cout<<endl;
}

int main(int argc,char* argv[]){
  Pune(v,sf,1);Pune(v,sf,2);
  Pune(v,sf,3);listare(v);
  Scoate(v);listare(v);
  Scoate(v);listare(v);
  Scoate(v);
  Scoate(v);

  return 0;
}
