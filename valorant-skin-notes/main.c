#include<stdio.h>
#include<string.h>

struct simpan{
    char namaSkin[101];
    char Edition[101];
    char Weapon[101];
};

//menyimpan total data edisi
int SelectEd    =   0;
int DeluxeEd    =   0;
int PremiumEd   =   0;
int ExclusiveEd =   0;
int UltraEd     =   0;
int OtherEd     =   0;

void editionCount(struct simpan data[], int IndexSkin){
    if(strcmp(data[IndexSkin].Edition,"select")==0){
        SelectEd++;
    }else if(strcmp(data[IndexSkin].Edition,"deluxe")==0){
        DeluxeEd++;
    }else if(strcmp(data[IndexSkin].Edition,"premium")==0){
        PremiumEd++;
    }else if(strcmp(data[IndexSkin].Edition,"exclusive")==0){
        ExclusiveEd++;
    }else if(strcmp(data[IndexSkin].Edition,"ultra")==0){
        UltraEd++;
    }else{
        OtherEd++;
    }
}

void simpanFile(char namafile[]){
    printf("Masukan nama file: ");
    scanf(" %[^\n]", namafile);
    strcat(namafile,".csv");
}

int main() {
    struct simpan data[1001];

    //opsi untuk memilih apakah data sudah cukup atau belum
    char lanjut[10];

    //menyimpan data skin yang dimasukan
    int IndexSkin   =   1;
    int totalSkin   =   0;

    char opsi1[101];
    printf("Write or Append?(w/a): ");
    scanf("%s",opsi1);
    
    do{

        //nama skin
        printf("Masukan Nama Skin(lowercase): ");
        scanf(" %[^\n]", &data[IndexSkin].namaSkin);

        //weapon
        printf("Masukan Tipe Weapon(lowercase): ");
        scanf("%s",data[IndexSkin].Weapon);

        //edition
        printf("Masukan Edition(lowercase): ");
        scanf("%s",data[IndexSkin].Edition);

        //call function
        editionCount(data, IndexSkin);

        //nomor skin dan total count
        IndexSkin++;
        totalSkin++;

        printf("Apakah masih ada lagi?(y/n): ");
        scanf("%s", &lanjut);

    }while(strcmp(lanjut,"n")!=0);


    //nama file
    char filename[101];
    simpanFile(filename);
    FILE*rd = fopen(filename,opsi1);


    //printing
    if(strcmp(opsi1,"w")==0){
        fprintf(rd,"No,Nama Skin,Weapon,Edition\n");
    }
    
    for(int idx = 1; idx <= IndexSkin; idx++){
        fprintf(rd,"%s,%s,%s\n",data[idx].namaSkin,data[idx].Weapon,data[idx].Edition);
    }
    fclose(rd);

    //info tambahan
    printf("\n((===JUMLAH EDISI SKIN===))\n");
    printf("Jumlah Skin Select Edition      : %d\n",SelectEd);
    printf("Jumlah Skin Deluxe Edition      : %d\n", DeluxeEd);
    printf("Jumlah Skin Premium Edition     : %d\n", PremiumEd);
    printf("Jumlah Skin Exclusive Edition   : %d\n", ExclusiveEd);
    printf("Jumlah Skin Ultra Edition       : %d\n", UltraEd);
    printf("Jumlah Skin Lainnya             : %d\n", OtherEd);
    
    return 0;
}