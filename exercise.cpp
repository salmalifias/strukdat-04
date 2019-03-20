/*
Nama		: Salma Alifia Shafira
NPM			: 140810180058
Kelas		: B
Tanggal		: 20 Maret 2019
*/

#include<iostream>
using namespace std;

struct Elemtlist{
	char NmPnjngPgwi[50];
	char divisi[20];
	int gaji;
	Elemtlist* next;
};
typedef Elemtlist* pointer;
typedef pointer List;

void createlist(List& gajipegawai){
	gajipegawai=NULL;
}
void createElement(pointer& pBaru){
	pBaru= new Elemtlist;
	cout<<"Nama	:";
	cin.ignore();cin.getline(pBaru->NmPnjngPgwi,30);
	cout<<"Divisi	:";
    cin.ignore();cin.getline(pBaru->divisi,30);
    cout<<"Gaji	:";cin>>pBaru->gaji;
    pBaru->next=NULL;
}

void insertFirst(List& gajipegawai,pointer pBaru){
	if(gajipegawai==NULL){
		gajipegawai=pBaru;
	}
	else{
		pBaru->next=gajipegawai;
		gajipegawai=pBaru;
	}
}

void traversal(List gajipegawai){
	int i;
	i=1;
	pointer pBantu;
	pBantu=gajipegawai;
	cout<<"		  Data Pegawai"<<endl;
	cout<<"======================================================="<<endl;
	cout<<"No | Nama		| Bidang		| Gaji"<<endl;
	cout<<"-----------------------------------------------------"<<endl;
	while(pBantu != NULL) {
		cout<<i<<"  | "<<pBantu->NmPnjngPgwi<<"		| "<<pBantu->divisi<<"			| "<<pBantu->gaji;
		pBantu=pBantu->next;
		i++;
		cout<<endl;
	}
	cout<<"======================================================="<<endl;
}

void insertLast(List& gajipegawai, pointer pBaru){
	pointer last;
	if (gajipegawai==NULL){
		gajipegawai=pBaru;
	}
	else {
		last=gajipegawai;
		while (last->next!=NULL){
			last=last->next;
		}
		last->next=pBaru;
	}
}
void deleteFirst(List& gajipegawai, pointer& pHapus){
	if (gajipegawai==NULL){
		pHapus=NULL;
		cout << "List masih kosong" << endl;
	}
	else if (gajipegawai->next==NULL){
		pHapus=gajipegawai;
		gajipegawai=NULL;
	}
	else {
		pHapus=gajipegawai;
		gajipegawai=gajipegawai->next;
		pHapus->next=NULL;
	}
}

void deleteLast(List& gajipegawai, pointer& pHapus){
	pointer last,precLast;
	if (gajipegawai==NULL){
		pHapus=NULL;
		cout << "List masih kosong" << endl;
	}
	else if (gajipegawai->next==NULL){
		pHapus=gajipegawai;
		gajipegawai=NULL;
	}
	else {
		last=gajipegawai;
		precLast=NULL;
		while (last->next!=NULL){
			precLast=last;
			last=last->next;
		}
		pHapus=last;
		precLast->next=NULL;
	}
}
int main(){
	pointer p,pHapus;
	List list;
	int n,x;
	createlist(list);
	while(x!=5){
		cout<<"Menu " << endl;
		cout<<"1. Insert First"<<endl;
		cout<<"2. Insert Last"<<endl;
		cout<<"3. Delete First"<<endl;
		cout<<"4. Delete Last"<<endl;
		cout<<"5. Transversal"<<endl;
		cout<<"6. Exit"<<endl;
		cout<<"=========================="<<endl;
		cout<<"Masukkan pilihan : ";cin>>x;
		cout<<"=========================="<<endl;
		
		switch(x){
			case 1:
				cout<<"Masukan Banyak Pegawai : ";cin>>n;
				for(int i=0;i<n;i++){
					cout<<"\nMasukkan data Pegawai ke-"<<i+1<<endl;
					createElement(p);
					insertFirst(list,p);
				}
				traversal(list);
				cout<< endl;
				break;

			case 2:
				cout<<"Masukan Banyak Pegawai : ";
				cin>>n;
				cout<<endl;
				for(int i=0;i<n;i++){
					cout<<"\nMasukkan data Pegawai ke-"<<i+1<<endl;
					createElement(p);
					insertLast(list,p);
					cout<<endl;
				}
				traversal(list);
				cout<<endl;
				break;
			case 3:
				deleteFirst(list,pHapus);
				break;
			case 4:
				deleteLast(list,pHapus);
				break;
			case 5:
				traversal(list);
				break;
		}	
	}	
}


