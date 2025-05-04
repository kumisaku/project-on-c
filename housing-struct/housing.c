#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct house { //kumpulan data
    char location[50];
    char city[50];
    char price[50];
    char rooms[50];
    char bathroom[50];
    char carpark[50];
    char type[50];
    char furnish[50];
};

struct house data[5000];

//function untuk display data
void DisplayData(int numR) {
    printf("%-25s %-15s %-10s %-5s %-10s %-10s %-15s %-15s\n",
           "Location", "City", "Price", "Rooms", "Bathroom", "Carpark", "Type", "Furnish");
    for (int i = 0; i < numR; i++) {
        printf("%-25s %-15s %-10s %-5s %-10s %-10s %-15s %-15s\n",
               data[i].location, data[i].city, data[i].price, data[i].rooms,
               data[i].bathroom, data[i].carpark, data[i].type, data[i].furnish);
    } //melakukan printing sesuai jumlah baris yang di input user
}

//function untuk melakukan searching data
void SearchData (char col[], char colOpt[], int total){
    if(strcmp(col,"Location")==0){
        for(int i=0;i<total;i++){
            if(strcmp(data[i].location,colOpt)==0){
            printf("%-25s %-15s %-10s %-5s %-10s %-10s %-15s %-15s\n",
                data[i].location, data[i].city, data[i].price, data[i].rooms,
                data[i].bathroom, data[i].carpark, data[i].type, data[i].furnish);
            }
        }
    }
    else if(strcmp(col,"City")==0){
        for(int i=0;i<total;i++){
            if(strcmp(data[i].city,colOpt)==0){
            printf("%-25s %-15s %-10s %-5s %-10s %-10s %-15s %-15s\n",
                data[i].location, data[i].city, data[i].price, data[i].rooms,
                data[i].bathroom, data[i].carpark, data[i].type, data[i].furnish);
            }
        }
    }
    else if(strcmp(col,"Price")==0){
        for(int i=0;i<total;i++){
            if(strcmp(data[i].price,colOpt)==0){
            printf("%-25s %-15s %-10s %-5s %-10s %-10s %-15s %-15s\n",
                data[i].location, data[i].city, data[i].price, data[i].rooms,
                data[i].bathroom, data[i].carpark, data[i].type, data[i].furnish);
            }
        }
    }
    else if(strcmp(col,"Rooms")==0){
        for(int i=0;i<total;i++){
            if(strcmp(data[i].rooms,colOpt)==0){
            printf("%-25s %-15s %-10s %-5s %-10s %-10s %-15s %-15s\n",
                data[i].location, data[i].city, data[i].price, data[i].rooms,
                data[i].bathroom, data[i].carpark, data[i].type, data[i].furnish);
            }
        }
    }
    else if(strcmp(col,"Bathroom")==0){
        for(int i=0;i<total;i++){
            if(strcmp(data[i].bathroom,colOpt)==0){
            printf("%-25s %-15s %-10s %-5s %-10s %-10s %-15s %-15s\n",
                data[i].location, data[i].city, data[i].price, data[i].rooms,
                data[i].bathroom, data[i].carpark, data[i].type, data[i].furnish);
            }
        }
    }
    else if(strcmp(col,"Carpark")==0){
        for(int i=0;i<total;i++){
            if(strcmp(data[i].carpark,colOpt)==0){
            printf("%-25s %-15s %-10s %-5s %-10s %-10s %-15s %-15s\n",
                data[i].location, data[i].city, data[i].price, data[i].rooms,
                data[i].bathroom, data[i].carpark, data[i].type, data[i].furnish);
            }
        }
    }
    else if(strcmp(col, "Type")==0){
        for(int i=0;i<total;i++){
            if(strcmp(data[i].type,colOpt)==0){
            printf("%-25s %-15s %-10s %-5s %-10s %-10s %-15s %-15s\n",
                data[i].location, data[i].city, data[i].price, data[i].rooms,
                data[i].bathroom, data[i].carpark, data[i].type, data[i].furnish);
            }
        }
    }
    else if(strcmp(col, "Furnish")==0){
        for(int i=0;i<total;i++){
            if(strcmp(data[i].furnish,colOpt)==0){
            printf("%-25s %-15s %-10s %-5s %-10s %-10s %-15s %-15s\n",
                data[i].location, data[i].city, data[i].price, data[i].rooms,
                data[i].bathroom, data[i].carpark, data[i].type, data[i].furnish);
            }
        }
    }
    //melakukan searching sesuai column dan data yang ingin dicari oleh user
}

//function untuk melakukan sort data sesuai input kolom yang dipilih user secara ascending dan descending
void SortData(char col3[], char sord[], int total){
    if(strcmp(col3, "Location")==0){
        if(strcmp(sord, "asc")==0){
            for(int i =0;i<total-1;i++){
                struct house temp;
                for(int j = 0; j < total - i - 1;j++){
                    if(strcmp(data[j].location,data[j+1].location) > 0 ){
                        temp = data[j];
                        data[j] = data[j+1];
                        data[j+1] = temp;
                    }
                }
            }
        }
        else if(strcmp(sord,"dsc")==0){
            for(int i =0;i<total-1;i++){
                struct house temp;
                for(int j = 0; j < total - i - 1;j++){
                    if(strcmp(data[j].location,data[j+1].location) < 0){
                        temp = data[j];
                        data[j] = data[j+1];
                        data[j+1] = temp;
                    }
                }
            }
        }
    }
    else if(strcmp(col3, "City")==0){
        if(strcmp(sord, "asc")==0){
            for(int i =0;i<total-1;i++){
                struct house temp;
                for(int j = 0; j < total - i - 1;j++){
                    if(strcmp(data[j].city,data[j+1].city) > 0 ){
                        temp = data[j];
                        data[j] = data[j+1];
                        data[j+1] = temp;
                    }
                }
            }
        }
        else if(strcmp(sord,"dsc")==0){
            for(int i =0;i<total-1;i++){
                struct house temp;
                for(int j = 0; j < total - i - 1;j++){
                    if(strcmp(data[j].city,data[j+1].city) < 0){
                        temp = data[j];
                        data[j] = data[j+1];
                        data[j+1] = temp;
                    }
                }
            }
        }
    }
    else if(strcmp(col3, "Price")==0){
        if(strcmp(sord, "asc")==0){
            for(int i =0;i<total-1;i++){
                struct house temp;
                for(int j = 0; j < total - i - 1;j++){
                    if(strcmp(data[j].price,data[j+1].price) > 0 ){
                        temp = data[j];
                        data[j] = data[j+1];
                        data[j+1] = temp;
                    }
                }
            }
        }
        else if(strcmp(sord,"dsc")==0){
            for(int i =0;i<total-1;i++){
                struct house temp;
                for(int j = 0; j < total - i - 1;j++){
                    if(strcmp(data[j].price,data[j+1].price) < 0){
                        temp = data[j];
                        data[j] = data[j+1];
                        data[j+1] = temp;
                    }
                }
            }
        }
    }
    else if(strcmp(col3, "Rooms")==0){
        if(strcmp(sord, "asc")==0){
            for(int i =0;i<total-1;i++){
                struct house temp;
                for(int j = 0; j < total - i - 1;j++){
                    if(strcmp(data[j].rooms,data[j+1].rooms) > 0 ){
                        temp = data[j];
                        data[j] = data[j+1];
                        data[j+1] = temp;
                    }
                }
            }
        }
        else if(strcmp(sord,"dsc")==0){
            for(int i =0;i<total-1;i++){
                struct house temp;
                for(int j = 0; j < total - i - 1;j++){
                    if(strcmp(data[j].rooms,data[j+1].rooms) < 0){
                        temp = data[j];
                        data[j] = data[j+1];
                        data[j+1] = temp;
                    }
                }
            }
        }
    }
    else if(strcmp(col3, "Bathroom")==0){
        if(strcmp(sord, "asc")==0){
            for(int i =0;i<total-1;i++){
                struct house temp;
                for(int j = 0; j < total - i - 1;j++){
                    if(strcmp(data[j].bathroom,data[j+1].bathroom) > 0 ){
                        temp = data[j];
                        data[j] = data[j+1];
                        data[j+1] = temp;
                    }
                }
            }
        }
        else if(strcmp(sord,"dsc")==0){
            for(int i =0;i<total-1;i++){
                struct house temp;
                for(int j = 0; j < total - i - 1;j++){
                    if(strcmp(data[j].bathroom,data[j+1].bathroom) < 0){
                        temp = data[j];
                        data[j] = data[j+1];
                        data[j+1] = temp;
                    }
                }
            }
        }
    }
    else if(strcmp(col3, "Carpark")==0){
        if(strcmp(sord, "asc")==0){
            for(int i =0;i<total-1;i++){
                struct house temp;
                for(int j = 0; j < total - i - 1;j++){
                    if(strcmp(data[j].carpark,data[j+1].carpark) > 0 ){
                        temp = data[j];
                        data[j] = data[j+1];
                        data[j+1] = temp;
                    }
                }
            }
        }
        else if(strcmp(sord,"dsc")==0){
            for(int i =0;i<total-1;i++){
                struct house temp;
                for(int j = 0; j < total - i - 1;j++){
                    if(strcmp(data[j].carpark,data[j+1].carpark) < 0){
                        temp = data[j];
                        data[j] = data[j+1];
                        data[j+1] = temp;
                    }
                }
            }
        }
    }
    else if(strcmp(col3, "Type")==0){
        if(strcmp(sord, "asc")==0){
            for(int i =0;i<total-1;i++){
                struct house temp;
                for(int j = 0; j < total - i - 1;j++){
                    if(strcmp(data[j].type,data[j+1].type) > 0 ){
                        temp = data[j];
                        data[j] = data[j+1];
                        data[j+1] = temp;
                    }
                }
            }
        }
        else if(strcmp(sord,"dsc")==0){
            for(int i =0;i<total-1;i++){
                struct house temp;
                for(int j = 0; j < total - i - 1;j++){
                    if(strcmp(data[j].type,data[j+1].type) < 0){
                        temp = data[j];
                        data[j] = data[j+1];
                        data[j+1] = temp;
                    }
                }
            }
        }
    }
    else if(strcmp(col3, "Furnish")==0){
        if(strcmp(sord, "asc")==0){
            for(int i =0;i<total-1;i++){
                struct house temp;
                for(int j = 0; j < total - i - 1;j++){
                    if(strcmp(data[j].furnish,data[j+1].furnish) > 0 ){
                        temp = data[j];
                        data[j] = data[j+1];
                        data[j+1] = temp;
                    }
                }
            }
        }
        else if(strcmp(sord,"dsc")==0){
            for(int i =0;i<total-1;i++){
                struct house temp;
                for(int j = 0; j < total - i - 1;j++){
                    if(strcmp(data[j].furnish,data[j+1].furnish) < 0){
                        temp = data[j];
                        data[j] = data[j+1];
                        data[j+1] = temp;
                    }
                }
            }
        }
    }
    for(int i=0;i<10;i++){
        printf("%-25s %-15s %-10s %-5s %-10s %-10s %-15s %-15s\n",
            data[i].location, data[i].city, data[i].price, data[i].rooms,
            data[i].bathroom, data[i].carpark, data[i].type, data[i].furnish);
    }
}

//function untuk saving file dengan nama yang sesuai dengan yang user input
void ExportFile(char fileName[], int total){
    FILE*nw = fopen(fileName,"w");
    fprintf(nw,"%s,%s,%s,%s,%s,%s,%s,%s\n","Location", "Location2", "Price", "Rooms", "Bathrooms", "Carpark", "Type", "Furnish");
    for(int i =0; i < total;i++){
        fprintf(nw, "%s,%s,%s,%s,%s,%s,%s,%s\n",
        data[i].location, data[i].city, data[i].price, data[i].rooms,
        data[i].bathroom, data[i].carpark, data[i].type, data[i].furnish);
    }
    printf("Data succesfully written to file %s!\n", fileName);
    fclose(nw);
}

int main() {
    int chooseOption; // untuk Opsi select pada program
    char header[500]; // variable untuk header pada file CSV
    FILE *frd = fopen("file.csv", "r"); //membuka file untuk di read
	fscanf(frd, "%[^\n]\n", header); //read header pada file CSV
    
    if (frd == NULL) {
        printf("Error: Unable to open file.\n");
        return 1;
    }

    int totalR = 0;   // observasi jumlah data
    while (totalR < 5000 && 
           fscanf(frd, "%49[^,],%49[^,],%49[^,],%49[^,],%49[^,],%49[^,],%49[^,],%49[^\n]\n",
                  data[totalR].location, data[totalR].city, &data[totalR].price, 
                  &data[totalR].rooms, &data[totalR].bathroom, &data[totalR].carpark, 
                  data[totalR].type, data[totalR].furnish) == 8) {
        totalR++;
    } //scanning jumlah data yang terdapat pada file CSV
    fclose(frd); //menutup file

    //memilih opsi sesuai dengan input user
    do{
    printf("\n");
    printf("What do you want to do?\n");
    printf("1. Display data\n");
    printf("2. Search Data\n");
    printf("3. Sort Data\n");
    printf("4. Export Data\n");
    printf("5. Exit\n");
    printf("Your choice(1/2/3/4/5): ");
    scanf("%d", &chooseOption);

    //kondisi bila user input = 1
    if (chooseOption == 1) {
        int numRows;
        do{
        printf("Number of rows: ");
        scanf("%d", &numRows);
        if(numRows < 1)printf("Please put a positive number!(number > 0)\n");
        }while(numRows < 1);
        if(numRows > totalR)numRows = totalR;
        DisplayData(numRows);
    }

    //kondisi bila user input = 2
    else if(chooseOption == 2){
        char col[101], colOpt[101];
        bool isFound = false;
        do {
            printf("Choose column(Location/City/Price/Rooms/Bathroom/Carpark/Type/Furnish): ");
            scanf("%s", col);
            if((strcmp(col, "Location") != 0 && strcmp(col, "City") != 0 && strcmp(col, "Price") != 0 && strcmp(col, "Rooms") != 0 &&
                strcmp(col, "Bathroom") != 0 && strcmp(col, "Carpark") != 0 && strcmp(col, "Type") != 0 && strcmp(col, "Furnish") != 0)){
                    printf("Not Found. Please put valid column!\n");
                }
        } while (strcmp(col, "Location") != 0 &&
                strcmp(col, "City") != 0 &&
                strcmp(col, "Price") != 0 &&
                strcmp(col, "Rooms") != 0 &&
                strcmp(col, "Bathroom") != 0 &&
                strcmp(col, "Carpark") != 0 &&
                strcmp(col, "Type") != 0 &&
                strcmp(col, "Furnish") != 0);
        printf("What data do you want to find? ");
        scanf("%s", colOpt);

        for(int i=0;i<totalR;i++){
            if(strcmp(col, "Location")==0){
                if(strcmp(data[i].location,colOpt)==0){
                    isFound = true;
                    break;
                }
            }else if(strcmp(col,"City")==0){
                if(strcmp(data[i].city,colOpt)==0){
                    isFound = true;
                    break;
                }
            }else if(strcmp(col,"Price")==0){
                if(strcmp(data[i].price,colOpt)==0){
                    isFound = true;
                    break;
                }
            }else if(strcmp(col,"Rooms")==0){
                if(strcmp(data[i].rooms,colOpt)==0){
                isFound = true;
                break;
                }
            }else if(strcmp(col,"Bathroom")==0){
                if(strcmp(data[i].bathroom,colOpt)==0){
                    isFound = true;
                    break;
                }
            }else if(strcmp(col,"Carpark")==0){
                if(strcmp(data[i].carpark,colOpt)==0){
                    isFound = true;
                    break;
                }
            }else if(strcmp(col,"Type")==0){
                if(strcmp(data[i].type,colOpt)==0){
                    isFound = true;
                    break;
                }
            }else if(strcmp(col,"Furnish")==0){
                if(strcmp(data[i].furnish,colOpt)==0){
                    isFound = true;
                    break;
                }
            }else{
                isFound = false;
            }
        }
        if(isFound){
            printf("Data found. Detail of data:\n");
            printf("%-25s %-15s %-10s %-5s %-10s %-10s %-15s %-15s\n","Location", "City", "Price", "Rooms", "Bathroom", "Carpark", "Type", "Furnish");
            SearchData(col,colOpt,totalR);
            isFound = false;
        }else{
            printf("Data not found!\n");
            isFound = false;
        }

    }

    //kondisi bila user input = 3
    else if(chooseOption == 3){
        char col3[101], sord[101];
        do {
            printf("Choose column(Location/City/Price/Rooms/Bathroom/Carpark/Type/Furnish): ");
            scanf("%s", col3);
            if((strcmp(col3, "Location") != 0 && strcmp(col3, "City") != 0 && strcmp(col3, "Price") != 0 && strcmp(col3, "Rooms") != 0 &&
                strcmp(col3, "Bathroom") != 0 && strcmp(col3, "Carpark") != 0 && strcmp(col3, "Type") != 0 && strcmp(col3, "Furnish") != 0)){
                    printf("Not Found. Please put valid column!\n");
                }
        } while (strcmp(col3, "Location") != 0 &&
                strcmp(col3, "City") != 0 &&
                strcmp(col3, "Price") != 0 &&
                strcmp(col3, "Rooms") != 0 &&
                strcmp(col3, "Bathroom") != 0 &&
                strcmp(col3, "Carpark") != 0 &&
                strcmp(col3, "Type") != 0 &&
                strcmp(col3, "Furnish") != 0);
        do{
        printf("Sort ascending or descending?(asc/dsc): ");
        scanf("%s", sord);
        if(strcmp(sord,"asc")!=0 && strcmp(sord,"dsc")!=0)printf("Please put a valid input!\n");
        }while(strcmp(sord,"asc")!=0 && strcmp(sord,"dsc")!=0);

        printf("Data found. Detail of data:\n");
        printf("%-25s %-15s %-10s %-5s %-10s %-10s %-15s %-15s\n","Location", "City", "Price", "Rooms", "Bathroom", "Carpark", "Type", "Furnish");
        SortData(col3, sord, totalR);
    }

    //kondisi bila user input = 4
    else if(chooseOption == 4){
        char fileName[101];
        printf("File name: ");
        scanf("%s", fileName);
        strcat(fileName, ".csv");
        ExportFile(fileName,totalR);
    }
    
    //kondisi bila user input = 5
    //keluar dari program
    else if(chooseOption == 5){
        printf("See you Again!\n");
        exit(0);
    }
    else printf("\nPLEASE PUT A VALID/AVAILABLE OPTION!\n");
    }while(chooseOption != 5);
    return 0;
}
