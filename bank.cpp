#include <iostream>
#include <ctime>
#include <limits>
#include <chrono>
#include <thread>
#include <vector>
#include <string>
#include <map>
#include <cstdlib>
#include <ctime>
using namespace std;

vector<map<string, string>> banks;

// ========================== struct start =======================
//define time with struct skrg
struct Waktu{
	time_t skrg = time(0);
	tm *detik = localtime(&skrg);
		
	int tanggal(){
		return detik->tm_mday;
	}
	int bulan(){
		return detik->tm_mon;
	}
	int tahun(){
		return 1900 + detik->tm_year;
	}
	

//define month 
	void namaBulan(int bulan){		
		switch(bulan){
			case 0:
				std::cout << "Januari" ;
				break;
			case 1:
				std::cout << "Februari" ;
				break;
			case 2:
				std::cout << "Maret" ;
				break;
			case 3:
				std::cout << "April" ;
				break;
			case 4:
				std::cout << "Mei" ;
				break;
			case 5:
				std::cout << "Juni" ;
				break;
			case 6:
				std::cout << "Juli" ;
				break;
			case 7:
				std::cout << "Agustus" ;
				break;
			case 8:
				std::cout << "September" ;
				break;
			case 9:
				std::cout << "Oktober" ;
				break;
			case 10:
				std::cout << "November" ;
				break;
			case 11:
				std::cout << "Desember" ;
				break;
		}
	}

	int cariUmur(std::string tglLahir){
		//DD/MM/YYYY
		int umur;
		//kalau input bukan merupakan angka, program langsung termninate
		int tglLhr = stoi(tglLahir.substr(0,2));
		int blnLhr = stoi(tglLahir.substr(3,2)) - 1; //bulan dimulai dari 0 hingga 11
		int thnLhr = stoi(tglLahir.substr(6,4));
		if((tglLhr > 31 || tglLhr < 1) || (blnLhr > 11 || blnLhr < 0) || (thnLhr >= tahun() || thnLhr <= 1000)){ //kalau inputnya tidak sesuai
			std::cout << "Input tanggal Salah!\n";
			return 0;
		}
		umur = tahun() - thnLhr;		
		if(bulan() <= blnLhr){
			umur -=1;
			if(tanggal() < tglLhr) umur +=1;
		}		
		return umur;
	}
	
	void jatuhTempo(){
		int tgl = tanggal();
		int bln = bulan() + 1; // Bulan depannya
		int thn = tahun();
		if(bln == 12){// Kalau bulan ini bulan desember, dibuat jadi Januari, lalu tahun + 1
			thn += 1; 
			bln = 0;
		} 
	//	std::cout << tanggal << " " << bulanTempo << " " << tahun << std::endl;
		std::cout << tgl << " ";
		namaBulan(bln);
		std::cout << " " << thn;
	}

};
// ============================ struct end =================================

// ================================= start Form ============================
struct Formulir{
	Waktu waktu;
	std::string nama;
	std::string tglLahir;
	int umur;
	std::string noKtp;
	std::string noTlp;
	std::string email;
	std::string alamat;
    std::string NPWP;
    int pendapatan;
    int randomNumber = rand() % 1000000000 + 1;
    

	void mengisi()
	{//	cin ga bisa handle white space
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //untuk mengatasi whitespace		
		std::cout << "Silahkan isi Formulir untuk membuat buku tabungan \n" << std::endl;
		std::cout << "Nama Lengkap\t: " ; std::getline(std::cin, nama);		
		do{
			std::cout << "Tanggal Lahir \n" ;
            std::cout << "(DD/MM/YYYY/)   : " ; std::cin >> tglLahir;
			umur = waktu.cariUmur(tglLahir);
		}
		while(!umur);
		std::cout << "Nomor KTP\t: " ; std::cin >> noKtp;
        std::cout << "Nomor NPWP\t: " ; std::cin >> NPWP;
		std::cout << "Nomor Telepon\t: " ; std::cin >> noTlp;
		std::cout << "E-Mail\t\t: " ; std::cin >> email;	
        std::cout << "Pendapatan\t: " ; std::cin >> pendapatan;
	//	cin masih meninggalkan value '\n'
		std::cout << "Alamat Tinggal\t: " ; std::getline(std::cin >> std::ws, alamat);	
        map<string, string> bank = {{"Nama", nama}, {"Telepon", noTlp}, {"KTP", noKtp}, {"NPWP", NPWP}};
        banks.push_back(bank);
        cout << "Book added successfully." << endl;
	}

	void tampil()
	{
		std::cout << "\n====================== Preview Buku Tabungan ======================\n" << std::endl;
		std::cout << "Nama Lengkap\t: " << nama;
		std::cout << "\nUmur\t\t: " << umur;
		std::cout << "\nNomor KTP\t: " << noKtp;
        std::cout << "\nNomor NPWP\t: " << NPWP;
		std::cout << "\nNomor Telepon\t: " << noTlp;
		std::cout << "\nE-Mail\t\t: " << email;
        std::cout << "\nPendapatan\t: " << pendapatan;
        std::cout << "\nNo. Tabungan\t: " << randomNumber;
		std::cout << "\nAlamat Tinggal\t: " << alamat << std::endl;
        // std::cout << "\nNo Tabungan\t: " << noKtp << std::endl;
		std::cout << "\n\n================================================================\n" << std::endl;

	}
 
    void updateBank() {
        cout << "Silahkan Masukan Nama Lengkap anda : ";
        std::cin >> nama;
        for (auto bank : banks) {
            if (bank["Nama"] == nama) {
                cout << "\n========== Silahkan Masukan Data Baru ==========\n ";
                cout << "Masukan Nama Lengkap : ";
                std::cin >> nama;
                cout << "Masukan No KTP : ";
                std::cin >> noKtp;
                cout << "Masukan No NPWP : ";
                std::cin >> NPWP;
                if (!nama.empty()) {
                    bank["Nama"] = nama;
                }
                if (!tglLahir.empty()) {
                    bank["KTP"] = noKtp;
                }
                if (!NPWP.empty()) {
                    bank["NPWP"] = NPWP;
                }
                cout << "Buku Tabungan Berhasil Diubah." << endl;
                return;
            }
        }cout << "Bank not found." << endl;
    }

    void deleteBank() {
    cout << "Enter the title of the book you want to delete: ";
    std::cin >> nama;
    for (auto it = banks.begin(); it != banks.end(); it++) {
        if ((*it)["title"] == nama) {
            banks.erase(it);
            cout << "Bank deleted successfully." << endl;
            return;
        }
    }
    cout << "Bank not found." << endl;
}
    
	void apakahBenar(){
		int sedangPilih = 0;
		do{
			tampil();
			std::cout << "\nAnda sudah yakin mengisi data dengan benar?" << std::endl;
			std::cout << "1.) Tidak\n2.) Ya\n\n";
			std::cin >> sedangPilih;
			if(sedangPilih != 1 && sedangPilih != 2) sedangPilih = 1;
			sedangPilih -= 1;
			if(!sedangPilih) mengisi();
		}
		while(!sedangPilih);
	}
};

// ============================================ end Form ====================================


// =================================== bool validate ========================================
bool cekValidasi(int umur, std::string noKtp, int pendapatan){
	//Ini hanya simulasi cek, no KTP diambil dari nomor NIM mahasiswa 
	std::string jelekKtp[] = {"411221022"};	
	bool tolak = false;	
	if(umur < 21){		
		std::cout << "Mohon maaf!\nAnda belum cukup umur!\nAnda kami tolak" << std::endl;
		
		tolak = true;
	}else if (pendapatan < 5000000){
        std::cout << "Mohon maaf!\nPendapatan anda kurang dari 5000000!\nAnda kami tolak" << std::endl;
        
        tolak = true;
    }
	for(int i = 0; i < sizeof(jelekKtp)/sizeof(jelekKtp[0]); i++){
		if(noKtp == jelekKtp[i]){
			std::cout << "Riwayat anda tercatat buruk!\nAnda kami tolak!" << std::endl;
			tolak = true;
			
			break;
		} 
	}
	return tolak;
}

// =================================== bool validate =======================================





// ##################################### MAIN ###############################################

int main(){											// ============ MAIN ==============
						//Deklarasi
	Formulir formulir;
	Waktu waktu;
    int bungkusNo = 0;
	int sedangPilih = 0;
    int pilihProduct = 0;
	std::string Product;	
	int harga;	
	int biayaAdmin;
	int totalHarga;
	int DP;
	int stlhDP;
	int angsur;
    int bunga;
    int bungaTotal;


						//Mulai
	std::cout << "\n\n====================== Selamat Datang Di BANK IT ======================\n\n\nSilahkan tekan enter untuk memulai!" << std::endl;
	formulir.mengisi();
	formulir.apakahBenar();						
	if (cekValidasi(formulir.umur, formulir.noKtp, formulir.pendapatan)) return 0;
	
												//setiap switch/pilihan, akan bermasalah kalau inputnya character
				//Memiliih Product
        int counter = 0;
        while (counter < 47) {
        std::cout << "  LOADING ";
        for (int i = 0; i < counter; i++) {
            std::cout << "#";
        }
        std::cout << "\r"; // move cursor back to start of line
        std::cout.flush(); // flush output stream to display changes immediately
        std::this_thread::sleep_for(std::chrono::milliseconds(80)); // delay 500ms
        counter++;
    }
    std::cout << "\n\n\n====================== Validated ====================== \n\n";
	
    do {
    std::cout << "\n=========== Selamat datang di MENU Bank IT ===========\n\n";
    std::cout << "Silahkan pilih MENU : )\n\n";
    std::cout << "1. Profil Buku Tabungan" << endl;
    std::cout << "2. Modifikasi Buku Tabungan" << endl;
    std::cout << "3. Riwayat Buku Tabungan" << endl;
    std::cout << "4. Menghapus Buku tabungan" << endl;
    std::cout << "5. KTA (Kredit Tanpa Agunan )" << endl;
    std::cout << "6. KPR (Kredit Pemilikan Rumah )" << endl;
    std::cout << "7. Keluar" << endl;
	std::cin >> pilihProduct;

        switch(pilihProduct) {
            case 5: // KTA
                std::cout << "Anda memilih KTA (Kredit Tanpa Agunan)\n\n";
                //KOdingan KTA disini
                do{
                    std::cout << "Silahkan pilih Product KTA ( Kredit Tanpa Agunan ) : ";
                    std::cout << "\n1.) Pernikahan";
                    std::cout << "\n2.) Dana Kebutuhan\n\n";
                    std::cin >> sedangPilih;		
                    switch(sedangPilih){
                        case 1:
                            Product = "Pernikahan";
                            harga = 10000000; //ini tampilin pakai dot
                            bunga = 10 / 100;
                            break;
                        case 2:
                            Product = "Dana Kebutuhan";
                            harga = 5000000; //ini tampilin pakai dot
                            bunga = 5 / 100;
                            break;
                        default:
                            std::cout << "Mohon memilih Product yang tersedia!\n";
                            sedangPilih = 0;
                            continue;
                    }
                    //Menanyakan apakah Cust sudah yakin.
                    std::cout << "Anda memilih Product KTA " << Product << std::endl;
                    std::cout << "Jumlah Total untuk Product KTA " << Product << " Rp "<< harga << std::endl;
                    std::cout << "Apakah anda yakin?\n1.) Tidak Yakin\n2.) Yakin\n";
                    std::cin >> sedangPilih;
                    if(sedangPilih != 1 && sedangPilih != 2) sedangPilih = 1;
                    sedangPilih -= 1;
                }	
                while(!sedangPilih);
                sedangPilih = 0;
                
                biayaAdmin = harga * 10 / 100;
                bungaTotal = harga * bunga;
                totalHarga = harga + biayaAdmin + bungaTotal;
                    
                            //Memilih DP
                // std::cout << "Kami menyediakan 2 pilihan DP." << std::endl;
                // do{
                //     std::cout << "Silahkan pilih DP." << std::endl;
                //     std::cout << "1.) DP Besar (30%)\n2.) DP Kecil (15%)\n";
                //     std::cin >> sedangPilih;
                //     switch(sedangPilih){
                //         case 1:
                //             DP = harga * 30 / 100;
                //             break;
                //         case 2:
                //             DP = harga * 15 / 100;
                //             break;
                //         default:
                //             std::cout << "Mohon memilih DP yang tersedia!\n";
                //             sedangPilih = 0;
                //             continue;
                //     }
                //     //Menanyakan apakah Cust sudah yakin.
                //     std::cout << "Jumlah DP = Rp. " << DP << std::endl;
                //     std::cout << "Jumlah biaya yang akan diangsur = Rp " << totalHarga - DP << std::endl;
                //     std::cout << "(Biaya sudah termasuk biaya angsuran bunga 10%)" << std::endl;
                //     std::cout << "Apakah anda yakin?\n1.) Tidak Yakin\n2.) Yakin\n";
                //     std::cin >> sedangPilih;
                //     if(sedangPilih != 1 && sedangPilih != 2) sedangPilih = 1;
                //     sedangPilih -= 1;
                // }
                // while(!sedangPilih);
                
                // sedangPilih = 0;
                
                
                
                            //memilih jangka waktu angsuran
                std::cout << "Kami menyediakan 2 pilihan jangka waktu angsuran.";					
                do{
                    std::cout << "Silahkan pilih lama angsuran." << std::endl;
                    std::cout << "1.) Jangka Panjang (36 bulan)\n2.) Jangka Pendek (12 Bulan)\n";
                    std::cin >> sedangPilih;
                    switch(sedangPilih){
                        case 1:
                            angsur = totalHarga / 36;
                            break;
                        case 2:
                            angsur = totalHarga / 12;
                            break;
                        default:
                            std::cout << "Mohon memilih Jangka Waktu yang tersedia!\n";
                            sedangPilih = 0;
                            continue;				
                    }
                    //Menanyakan apakah Cust sudah yakin.
                    std::cout << "Biaya angsuran per bulan = Rp" << angsur << std::endl;
                    std::cout << "Apakah anda yakin?\n1.) Tidak Yakin\n2.) Yakin\n";
                    std::cin >> sedangPilih;
                    if(sedangPilih != 1 && sedangPilih != 2) sedangPilih = 1;
                    sedangPilih -= 1;
                }
                while(!sedangPilih);
                
                sedangPilih = 0;
                
                            //Perjanjian Jual Beli dan Jatuh Tempo
                std::cout << "Berikut Data Transaksi anda : " << std::endl;
                std::cout << "Nama\t\t\t: " << formulir.nama << std::endl;
                std::cout << "No. KTP\t\t\t: " << formulir.noKtp << std::endl;
                std::cout << "Product\t\t\t: " << Product << std::endl;
                std::cout << "Angsuran per bulan\t: Rp " << angsur << std::endl;
                std::cout << "Denda per hari:\t\t: Rp" << angsur * 0.05 << std::endl;
                std::cout << "Jatuh Tempo\t\t: "; waktu.jatuhTempo();
                std::cout << std::endl;
                break;
                
            case 6: // KPR
                std::cout << "Anda memilih KPR (Kredit Pemilikan Rumah)\n\n";
                // Masukkan kode untuk pilihan KPR di sini
                do{
                std::cout << "Silahkan pilih Product KPR (Kredit Pemilikan Rumah) : ";
                std::cout << "\n1.) Rumah Tipe A";
                std::cout << "\n2.) Rumah Tipe B\n\n";
                std::cin >> sedangPilih;		
                switch(sedangPilih){
                    case 1:
                        Product = "Rumah Tipe A";
                        harga = 120000000; //ini tampilin pakai dot
                        break;
                    case 2:
                        Product = "Rumah Tipe A";
                        harga = 250000000; //ini tampilin pakai dot
                        break;
                    default:
                        std::cout << "Mohon memilih Product yang tersedia!\n";
                        sedangPilih = 0;
                        continue;
                }
                //Menanyakan apakah Cust sudah yakin.
                std::cout << "Anda memilih Product KPR " << Product << std::endl;
                std::cout << "Jumlah Total untuk Product KTA " << Product << " Rp "<< harga << std::endl;
                std::cout << "Apakah anda yakin?\n1.) Tidak Yakin\n2.) Yakin\n";
                std::cin >> sedangPilih;
                if(sedangPilih != 1 && sedangPilih != 2) sedangPilih = 1;
                sedangPilih -= 1;
                }	
                while(!sedangPilih);
                sedangPilih = 0;
                
                biayaAdmin = harga * 10 / 100;
                totalHarga = harga + biayaAdmin;
                    
                            //Memilih DP
                std::cout << "Kami menyediakan 2 pilihan DP." << std::endl;
                do{
                    std::cout << "Silahkan pilih DP." << std::endl;
                    std::cout << "1.) DP Besar (15%)\n2.) DP Kecil (10%)\n";
                    std::cin >> sedangPilih;
                    switch(sedangPilih){
                        case 1:
                            DP = harga * 15 / 100;
                            break;
                        case 2:
                            DP = harga * 10 / 100;
                            break;
                        default:
                            std::cout << "Mohon memilih DP yang tersedia!\n";
                            sedangPilih = 0;
                            continue;
                    }
                    //Menanyakan apakah Cust sudah yakin.
                    std::cout << "Jumlah DP = Rp. " << DP << std::endl;
                    std::cout << "Jumlah biaya yang akan diangsur = Rp " << totalHarga - DP << std::endl;
                    std::cout << "(Biaya sudah termasuk biaya angsuran bunga 10%)" << std::endl;
                    std::cout << "Apakah anda yakin?\n1.) Tidak Yakin\n2.) Yakin\n";
                    std::cin >> sedangPilih;
                    if(sedangPilih != 1 && sedangPilih != 2) sedangPilih = 1;
                    sedangPilih -= 1;
                }
                while(!sedangPilih);
                
                sedangPilih = 0;
                stlhDP = totalHarga - DP;
                
                            //memilih jangka waktu angsuran
                std::cout << "Kami menyediakan 2 pilihan jangka waktu angsuran.";					
                do{
                    std::cout << "Silahkan pilih lama angsuran." << std::endl;
                    std::cout << "1.) Jangka Panjang (10 Tahun)\n2.) Jangka Pendek (5 Tahun)\n";
                    std::cin >> sedangPilih;
                    switch(sedangPilih){
                        case 1:
                            angsur = stlhDP / 36;
                            break;
                        case 2:
                            angsur = stlhDP / 12;
                            break;
                        default:
                            std::cout << "Mohon memilih Jangka Waktu yang tersedia!\n";
                            sedangPilih = 0;
                            continue;				
                    }
                    //Menanyakan apakah Cust sudah yakin.
                    std::cout << "Biaya angsuran per bulan = Rp" << angsur << std::endl;
                    std::cout << "Apakah anda yakin?\n1.) Tidak Yakin\n2.) Yakin\n";
                    std::cin >> sedangPilih;
                    if(sedangPilih != 1 && sedangPilih != 2) sedangPilih = 1;
                    sedangPilih -= 1;
                }
                while(!sedangPilih);
                
                sedangPilih = 0;
                
                            //Perjanjian Jual Beli dan Jatuh Tempo
                std::cout << "Berikut Data Transaksi anda : " << std::endl;
                std::cout << "Nama\t\t\t: " << formulir.nama << std::endl;
                std::cout << "No. KTP\t\t\t: " << formulir.noKtp << std::endl;
                std::cout << "Product\t\t\t: " << Product << std::endl;
                std::cout << "Angsuran per bulan\t: Rp " << angsur << std::endl;
                std::cout << "Denda per bulan:\t: Rp" << angsur * 5/10 << std::endl;
                std::cout << "Jatuh Tempo\t\t: "; waktu.jatuhTempo();
                std::cout << std::endl;
                break;
                
            case 1:
                formulir.tampil();
                break;
            case 4:
                formulir.deleteBank();
                break;
            case 2:
                formulir.updateBank();
                formulir.tampil();
                break;
            case 3:
                cout << "\nBerikut Riwayat Transaksi Buku Tabungan Anda : \n" << endl;
                std::cout << "Nama\t\t\t: " << formulir.nama << std::endl;
                std::cout << "No. KTP\t\t\t: " << formulir.noKtp << std::endl;
                std::cout << "No. Tabungan\t\t: " << formulir.randomNumber << std::endl;
                std::cout << "Product\t\t\t: " << Product << std::endl;
                std::cout << "Angsuran per bulan\t: Rp " << angsur << std::endl;
                std::cout << "Denda per bulan:\t: Rp" << angsur * 5/10 << std::endl;
                std::cout << "Jatuh Tempo\t\t: "; waktu.jatuhTempo();
                std::cout << "\n\n" << Product << std::endl;
                break;
            case 7:
                cout << "Anda Telah Keluar dari MENU , Terimakasih Banyak " << endl;
                break;
            default:
                std::cout << "Mohon memilih MENU yang tersedia!\n";
                break;	
            }
    } while (pilihProduct != 7);
 
    return 0;
}

    
