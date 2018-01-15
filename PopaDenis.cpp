/*Popa Denis
Nr2. Simple cozi*/

#include<iostream>
using namespace std;

struct nod{
  int nr;
  nod* leg;
};

nod* v,*sf,*d,*c;
int val,val1,i,info,n;

int adaugare(nod*& v,nod*& sf,int val){
  nod* c;
  if(v==0){
    v=new(nod);
    v->nr=val;
    v->leg=0;
    sf=v;
  } else {
    c=new(nod);
    sf->leg=c;
    c->nr=val;
    c->leg=0;
    sf=c;
  }
};

int inserare_dupa(nod* v,nod*&sf,int val,int val1){
  nod* c=v,*d;
  while(c->nr!=val) c=c->leg;
  d=new nod;
  d->nr=val1;
  d->leg=c->leg;
  c->leg=d;
  if (d->leg==0) sf=d;
};

int inserare_inainte(nod*&v,int val,int val1){
  nod*c ,*d;
  if (v->nr==val){
    d=new nod;
    d->nr=val1;
    d->leg=v;
    v=d;
  } else {
    c=v;
    while (c->leg->nr!=val) c=c->leg;
    	d=new nod;
    d->nr=val1;
    d->leg=c->leg;
    c->leg=d;
  }
}

int sterge(nod*& v,nod*& sf,int val){
  nod* c,*man;
  if (v->nr==val){
    man=v;
    v=v->leg;
  } else {
    c=v;
    while(c->leg->nr!=val) c=c->leg;
    man=c->leg;
    c->leg=man->leg;
    if (man==sf) sf=c;
  }
  delete man;
}

int listare(nod* v){
  nod *c=v;
  while(c){
    cout<<c->nr<<" ";
    c=c->leg;
  }
  cout<<endl;
}

int main(int argc,char* argv[]){
  cout<<"Dati numarul de noduri:";cin>>n;
  for (i=1;i<=n;i++) {
    cout<<"info:";cin>>info;
    adaugare(v,sf,info);
  }
  listare(v);
  cout<<"inserati valoarea:";cin>>val1;
  cout<<"dupa nodul cu informatia:";cin>>val;
  inserare_dupa(v,sf,val,val1);
  listare(v);
  cout<<"inserati valoarea:";cin>>val1;
  cout<<"inaintea nodului cu informatia:";cin>>val;
  inserare_inainte(v,val,val1);
  listare(v);
  cout<<"stergeti nodul de informatie:";cin>>val;
  sterge(v,sf,val);
  listare(v);
  return 0;
}
