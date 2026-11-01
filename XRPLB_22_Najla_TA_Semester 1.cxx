#include<iostream>
#include<cstdlib>
#include<string>
#include<fstream>
#include<iomanip>
#include<ctime>
using namespace std;

int noantre1=1,noantre2=1,noantre3=1,noantre;
	string menu1,back,nama,pilpol,nik,norujuk,nokartu,umur,apa,janji,polia;
	string poli1[3][4]=
	{
		{"Dr. Fanesha (07:00-11:00)","Dr. Alex (11:00-15:00)","Dr. Fandra (15:00-19:00)","Dr. Yunita (19:00-23:00)"},
		{"Dr. Queen (07:00-11:00)","Dr. Dimas (11:00-15:00)","Dr. Almira (15:00-19:00)","Dr. Cen-Cen (19:00-23:00)"},
		{"Dr. Savier (07:00-11:00)","Dr. Zulfikar (11-00-15:00)","Dr. Trisya (15:00-19:00)","Dr. Nimala (19:00-23:00)"}
	};
int main () 
{
		do
		{
			system("cls");
		//judul dan menu utama
		cout<<"                  RUMAH SAKIT TANIA MEDIKA  "<<endl;
		cout<<"      ===============================================  "<<endl;
	cout<<"                  SISTEM ANTREAN MANDIRI     "<<endl; cout<<"      ===============================================  "<<endl;
	cout<<"Masukan Karakter Apa Saja Untuk Memulai Pendaftaran Mandiri : "<<endl;
	cin>>menu1;
	//input data diri
	cout<<"Harap Masukan Data Diri Anda : "<<endl;
	cout<<"* Pasien Yang Belum Cukup Umur Diharapkan Diisi Oleh Orang Tua."<<endl;
	// go to nama
	cin.ignore();
	nama_ulg:
	cout<<"Masukan Nama : ";
	getline(cin,nama);
	bool adahuruf=false;
	if (nama.empty())
	{
		system("cls");
			cout<<"Nama tidak boleh kosong."<<endl;

			goto nama_ulg;
	}
	for (int i=0;i<nama.length();i++)
	{
	       char a=nama[i];
	       if(isalpha(a))
	  {
		    adahuruf=true;
	}
	
	        if (isdigit(a))
		{
			system("cls");
			cout<<"Nama tidak boleh mengandung angka."<<endl;

			goto nama_ulg;
		}
	if(!isalpha(a) && a!=' ' && a!='-')
   	{
		    system("cls");
		    cout<<"Nama hanya boleh berisi huruf dengan spasi,dan karakter penghubung(-)"<<endl;
		    goto nama_ulg;
   	}
   	if(!adahuruf)
   	{
   		system("cls");
		    cout<<"Nama hanya boleh berisi huruf dengan spasi,dan karakter penghubung(-)"<<endl;
		    goto nama_ulg;
   	}
	}
	// go to umur
	umur_ulg:
	cout<<"Masukan Umur : ";
	getline(cin,umur);
		if (umur.empty())
	{
		system("cls");
			cout<<"Umur tidak boleh kosong."<<endl;

			goto umur_ulg;
	}
	for (int i=0;i<umur.length();i++)
	{
     	if (!isdigit(umur[i]))
		{
			system("cls");
			cout<<"Umur tidak boleh mengandung karakter selain angka."<<endl;

			goto umur_ulg;
		}
	}
	int umur2=atoi(umur.c_str());
	if (umur2>100|| umur2<=0)
	{
		system("cls");
		cout<<"Harap masukan umur anda dengan valid"<<endl;
		
		goto umur_ulg;
	}
	// go to nik <16 dan berupa huruf
	nik_ulg:
	cout<<"Masukan NIK (16 digit)  : ";
	getline(cin,nik);
	if (nik.empty())
	{
		system("cls");
			cout<<"NIK tidak boleh kosong."<<endl;
			
			goto nik_ulg;
	}
		for (int i=0;i<nik.length();i++)
	{
     	if (!isdigit(nik[i]))
		{
			system("cls");
			cout<<"Umur tidak boleh mengandung karakter selain angka."<<endl;

			goto nik_ulg;
		}
		if (!isdigit(nik[i]))
		{
			system("cls");
			cout<<"NIK tidak boleh mengandung huruf."<<endl;

			goto nik_ulg;
		}
	}
	if (nik.length()!=16)
	{
		system("cls");
		cout<<"NIK harus 16 digit."<<endl;
		goto nik_ulg;
	}

	
	//hiasan
	cout<<"      ===============================================  "<<endl;
	cout<<"      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  "<<endl;
	
	//pilihan umum apa bpjs
	apa_ulg:
	cout<<"1. Umum"<<endl;
	cout<<"2. BPJS"<<endl;
	cout<<"Pilih Salah Satu (1/2): ";
	getline(cin,apa);
	if (apa.empty())
	{
		system("cls");
		cout<<"Harap isi dengan sesuai!"<<endl;
			goto apa_ulg;
	}
	for (int i=0;i<apa.length();i++)
	{
     	if (!isdigit(apa[i]))
		{
			system("cls");
			cout<<"Harap masukan dengan angka (1 atau 2)."<<endl;

			goto apa_ulg;
		}
	}
	
	int apa1=atoi(apa.c_str());
	//kalo pilihan 1 dan 2
	if(apa1==2)
	{
		// go to nomor kartu 
		kartu_ulg:
		cout<<"Masukan Nomor Kartu BPJS Anda (13 digit) : ";
		getline(cin,nokartu);
		if (nokartu.empty())
		{
			system("cls");
			cout<<"Harap isi dengan sesuai!"<<endl;
			goto kartu_ulg;
		}
		for (int i=0;i<nokartu.length();i++)
	{
		if (!isdigit(nokartu[i]))
		{
			system("cls");
			cout<<"Nomor Kartu tidak boleh mengandung huruf."<<endl;

			goto kartu_ulg;
		}
	}
	if (nokartu.length()!=13)
	{
		system("cls");
		cout<<"Nomor Kartu harus 13 digit."<<endl;
		goto kartu_ulg;
	}
	// go to no rujukan
	rujuk_ulg:
		cout<<"Masukan Nomor Rujukan Anda (min 5;maks 19 digit) : ";
		getline(cin,norujuk);
		if (norujuk.empty())
		{
			system("cls");
			cout<<"Harap isi dengan sesuai!"<<endl;
			goto rujuk_ulg;
		}
		for (int i=0;i<norujuk.length();i++)
	{
		if (!isdigit(norujuk[i]))
		{
			system("cls");
			cout<<"Nomor Rujukan tidak boleh mengandung huruf."<<endl;
			goto rujuk_ulg;
		}
	}
		if (norujuk.length()>19 || norujuk.length()<5)
	{
		system("cls");
		cout<<"Nomor Rujukan minimal 5 dan maksimal 19 digit."<<endl;
		goto rujuk_ulg;
	}
	}
	else if(apa1>2 || apa1<1)
	{
			system("cls");
		cout<<"Harap masukan pilihan yang tersedia!"<<endl;
		goto apa_ulg;
	}
	
	//hiasan pembatas
	//cout<<"      ===============================================  "<<endl;
	system("cls");
	//loop go to pemilihan poli
	cout<<"Pilih Poli: "<<endl;
	poli_ulg:
	cout<<"1. Poli Umum"<<endl;
	cout<<"2. Poli Anak"<<endl;
	cout<<"3. Poli Gigi"<<endl;
	cout<<"Pilih Poli : ";
	getline(cin,polia);
	if (polia.empty())
	{
		system("cls");
			cout<<"Harap isi dengan sesuai!"<<endl;
			goto poli_ulg;
	}
	for (int i=0;i<polia.length();i++)
	{
     	if (!isdigit(polia[i]))
		{
			system("cls");
			cout<<"Harap masukan dengan angka (1-3)."<<endl;
			goto poli_ulg;
		}
	}
	
	int poli=atoi(polia.c_str());
	//tampilan kalo udah milih poli
	if(poli==1)
	{
		pilpol="Umum";
	}
	else if(poli==2)
	{
		pilpol="Anak";
	}
	else if(poli==3)
	{
		pilpol="Gigi";
	}
	else
	{
		system("cls");
		cout<<"Poli tidak tersedia, harap isi sesuai poli yang tersedia!"<<endl;
		goto poli_ulg;
	}
	//hiasan
	cout<<"      ===============================================  "<<endl;
	cout<<"                         Poli "<<pilpol<<endl;
	cout<<"      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  "<<endl;
	//desicion case jadwal jam dan loop go to jadwal
	
	jadwal_ulg:
	cout<<"JADWAL YANG TERSEDIA: "<<endl;
		if(poli==1)
		{
			cout<<"1. "<<poli1[0][0]<<endl;
	        cout<<"2. "<<poli1[0][1]<<endl;
	        cout<<"3. "<<poli1[0][2]<<endl;
        	cout<<"4. "<<poli1[0][3]<<endl;
        	cout<<"\nPILIH BERDASARKAN WAKTU JANJI TEMU: ";
	getline(cin,janji);
	if (janji.empty())
	{
		system("cls");
		cout<<"Harap isi dengan sesuai!"<<endl;
		goto jadwal_ulg;
	}
	for (int i=0;i<janji.length();i++)
	{
     	if (!isdigit(janji[i]))
		{
			system("cls");
			goto jadwal_ulg;
		}
	}
	  	}
		
		else if(poli==2)
		{
            cout<<"1. "<<poli1[1][0]<<endl;
	        cout<<"2. "<<poli1[1][1]<<endl;
	        cout<<"3. "<<poli1[1][2]<<endl;
        	cout<<"4. "<<poli1[1][3]<<endl;
        	cout<<"\nPILIH BERDASARKAN WAKTU JANJI TEMU: ";
	getline(cin,janji);
	if (janji.empty())
	{
		system("cls");
		cout<<"Harap isi dengan sesuai!"<<endl;
		goto jadwal_ulg;
	}
	for (int i=0;i<janji.length();i++)
	{
     	if (!isdigit(janji[i]))
		{
			system("cls");
			goto jadwal_ulg;
		}
	}
		}
		
		else if(poli==3)
		{
			cout<<"1. "<<poli1[2][0]<<endl;
	        cout<<"2. "<<poli1[2][1]<<endl;
	        cout<<"3. "<<poli1[2][2]<<endl;
        	cout<<"4. "<<poli1[2][3]<<endl;
        	cout<<"\nPILIH BERDASARKAN WAKTU JANJI TEMU: ";
	getline(cin,janji);
	if (janji.empty())
	{
		system("cls");
		cout<<"Harap isi dengan sesuai!"<<endl;
		goto jadwal_ulg;
	}
	for (int i=0;i<janji.length();i++)
	{
     	if (!isdigit(janji[i]))
		{
			system("cls");
			goto jadwal_ulg;
		}
	}
		}
		int janji2=atoi(janji.c_str());
	    if(janji2>4 || janji2<1)
		{
			system("cls");
			cout<<"Jadwal Tidak Tersedia. Pilih Berdasarkan Jadwal Yang Tersedia!"<<endl;
			goto jadwal_ulg;
		}
		system("cls");
	//tampilan akhir 
	time_t waktu_sekarang=time(0);
	char *dt=ctime(&waktu_sekarang);
	
			cout<<"      ===============================================  "<<endl;
	cout<<"                  RUMAH SAKIT TANIA MEDIKA"<<endl; 
	cout<<"           JL. AZIZAH SHELBY NO. 67, JAWA BARAT"<<endl; 
	    	cout<<"      ===============================================  "<<endl;
	 	if(poli==1)
		{
			noantre=noantre1;
			cout<<"        NOMOR ANTRIAN       : U-" <<setfill('0')<<setw(3)<<noantre<<endl; 
			noantre1++;
		}
		else if(poli==2)
		{
			noantre=noantre2;
			cout<<"        NOMOR ANTRIAN       : A-"<<setfill('0')<<setw(3)<<noantre<<endl;
			noantre2++;
		}
		else if(poli==3)
		{
			noantre=noantre3;
			cout<<"        NOMOR ANTRIAN       : G-"<<setfill('0')<<setw(3)<<noantre<<endl;
			noantre3++;
		}
		cout<<endl;
		cout<<"        Nama                : "<<nama<<endl;
		cout<<endl;
		cout<<"        Umur                : "<<umur<<endl;
		cout<<endl;
		cout<<"        NIK                 : "<<nik<<endl;
		cout<<endl;
		cout<<"        Poli                : "<<pilpol<<endl;
		cout<<endl;
		cout<<"        Dokter & janji temu : "<<poli1[poli -1][janji2 -1]<<endl;
		
           cout<<"      ===============================================  "<<endl;
           cout<<"        Waktu Cetak         : "<<dt;
           cout<<"      ===============================================  "<<endl;
	
 	//selesai pengisian
	cout<<"Silahkan Ambil Tiket Anda"<<endl;
	 // struk
	
	ofstream outFile("struk.txt");
		outFile<<"================================"<<endl;
	outFile<<"RUMAH SAKIT TANIA MEDIKA"<<endl; 
	outFile<<"JL. AZIZAH SHELBY NO. 67, JAWA BARAT"<<endl; 	    outFile<<"================================"<<endl;
		
	 	if(poli==1)
		{
			outFile<<"NOMOR ANTRIAN  : U-" <<setfill('0')<<setw(3)<<noantre<<endl; 
		}
		else if(poli==2)
		{
			outFile<<"NOMOR ANTRIAN  : A-"<<setfill('0')<<setw(3)<<noantre<<endl;
		}
		else if(poli==3)
		{
			outFile<<"NOMOR ANTRIAN  : G-"<<setfill('0')<<setw(3)<<noantre<<endl;
		}
		outFile<<endl;
		outFile<<"Nama           : "<<nama<<endl;
		outFile<<endl;
		outFile<<"Umur           : "<<umur<<endl;
		outFile<<endl;
		outFile<<"NIK            : "<<nik<<endl;
		outFile<<endl;
		outFile<<"Poli           : "<<pilpol<<endl;
		outFile<<endl;
		outFile<<"Dokter & janji temu  : "<<poli1[poli -1][janji2 -1]<<endl;
           outFile<<"================================"<<endl;
           outFile<<"Waktu Cetak  : "<<dt; outFile<<"================================"<<endl;
	outFile.close();
	//ambil struk
	cout<<"Semoga Lekas Sembuh!"<<endl;
	//loop kembali(x)
	do
	{
	cout<<"Kembali (x)"<<endl;
	cin>>back;
	if (back!="x"&& back!="X")
	{
		system("cls");
		cout<<"Dimohon untuk memasukan 'x' atau 'X' untuk kembali ke menu utama."<<endl;
	}
     }while (back!="x"&& back!="X");
}while(back=="x"||back=="X");
	return 0;
}