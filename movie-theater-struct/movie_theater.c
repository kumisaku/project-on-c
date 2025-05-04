#include <stdio.h>

void film_text();

struct penonton{ //data penonton
    char nama[101];
    int umur;
};

void batasan_umur(int pilihan, int *batas){
    if(pilihan == 1)*batas = 10;
    else if(pilihan == 2)*batas = 8;
    else if(pilihan == 3)*batas = 13;
    else *batas = 18;
}

void total_harga(int pilihan, int tiket, double *pricing){
    if(pilihan == 1)*pricing = 30.000; 
    else if(pilihan == 2)*pricing = 40.000;
    else if(pilihan == 3)*pricing = 50.000;
    else if(pilihan == 4)*pricing = 40.000;
    *pricing = *pricing * tiket;
}

int main(){
    printf("            WELCOME TO THE\n");
    film_text();
    printf("\n");
    int choose;
    double harga=0;
    do{
        printf("===FILM YANG TERSEDIA MINGGU INI===\n");
        printf("1. Transformer(10+)(Rp30.000)\n");
        printf("2. Avenger : End Game(8+)(Rp40.000)\n");
        printf("3. Kimi No Nawa(13+)(Rp50.000)\n");
        printf("4. Star Wars 1(18+)(Rp40.000)\n");
        printf("Pilih film yang ingin ditonton (1/2/3/4): ");
        scanf("%d", &choose);
        if(choose < 1 || choose > 4)printf("Film is not available!\n");
    }while(choose < 1 || choose > 4);

    int batas_umur = 0;
    batasan_umur(choose, &batas_umur);

    int ticket;
    do{
        printf("Enter the amount of tickets: ");
        scanf("%d", &ticket);
        if(ticket <= 0)printf("Please enter the valid amount!\n");
    }while(ticket <= 0);

    struct penonton orang[ticket];
    
    int i;
    printf("\n");
    for(i=0;i<ticket;i++){
        printf("Enter audience number to %d!\n", i+1);
        printf("Enter name: ");
        scanf(" %[^\n]", orang[i].nama);
        getchar();
        printf("Enter age: ");
        scanf("%d", &orang[i].umur);
        getchar();
    }
    //loop through the struct to qualify
    int peringatan=0;
    for(i=0;i<ticket;i++){
        printf("\n");
        if(orang[i].umur < batas_umur){
            peringatan+=1;
            printf("=====================ALERT!=====================\n");
            printf("AUDIENCE NUMBER %d DOES NOT QUALIFY TO THE AGE RULES!\n", i+1);
            printf("Nama : %s\n", &orang[i].nama);
            printf("Umur : %d\n", orang[i].umur);
            
        }
    }
    // condition if there is no warning
    if(peringatan == 0){
        printf("\n");
        printf("Enjoy your film!\n");
        printf("\n");
        printf("======RECEIPT======\n");
        for(i=0;i<ticket;i++){
            printf("Audience number %d\n",i+1);
            printf("Name : %s\n", &orang[i].nama);
            printf("Age : %d\n", orang[i].umur);
        }
        printf("\n");
        total_harga(choose, ticket, &harga);
        printf("Price Amount = Rp%.3lf", harga);
    }
    return 0;
}

void film_text(){
    printf("███████╗██╗██╗░░░░░███╗░░░███╗\n");
    printf("██╔════╝██║██║░░░░░████╗░████║\n");
    printf("█████╗░░██║██║░░░░░██╔████╔██║\n");
    printf("██╔══╝░░██║██║░░░░░██║╚██╔╝██║\n");
    printf("██║░░░░░██║███████╗██║░╚═╝░██║\n");
    printf("╚═╝░░░░░╚═╝╚══════╝╚═╝░░░░░╚═╝\n");
}

void selamat_text(){
    printf("░██████╗███████╗██╗░░░░░░█████╗░███╗░░░███╗░█████╗░████████╗\n");
    printf("██╔════╝██╔════╝██║░░░░░██╔══██╗████╗░████║██╔══██╗╚══██╔══╝\n");
    printf("╚█████╗░█████╗░░██║░░░░░███████║██╔████╔██║███████║░░░██║░░░\n");
    printf("░╚═══██╗██╔══╝░░██║░░░░░██╔══██║██║╚██╔╝██║██╔══██║░░░██║░░░\n");
    printf("██████╔╝███████╗███████╗██║░░██║██║░╚═╝░██║██║░░██║░░░██║░░░\n");
    printf("╚═════╝░╚══════╝╚══════╝╚═╝░░╚═╝╚═╝░░░░░╚═╝╚═╝░░╚═╝░░░╚═╝░░░\n");
}

void menonton_text(){
    printf("███╗░░░███╗███████╗███╗░░██╗░█████╗░███╗░░██╗████████╗░█████╗░███╗░░██╗██╗\n");
    printf("████╗░████║██╔════╝████╗░██║██╔══██╗████╗░██║╚══██╔══╝██╔══██╗████╗░██║██║\n");
    printf("██╔████╔██║█████╗░░██╔██╗██║██║░░██║██╔██╗██║░░░██║░░░██║░░██║██╔██╗██║██║\n");
    printf("██║╚██╔╝██║██╔══╝░░██║╚████║██║░░██║██║╚████║░░░██║░░░██║░░██║██║╚████║╚═╝\n");
    printf("██║░╚═╝░██║███████╗██║░╚███║╚█████╔╝██║░╚███║░░░██║░░░╚█████╔╝██║░╚███║██╗\n");
    printf("╚═╝░░░░░╚═╝╚══════╝╚═╝░░╚══╝░╚════╝░╚═╝░░╚══╝░░░╚═╝░░░░╚════╝░╚═╝░░╚══╝╚═╝\n");
}