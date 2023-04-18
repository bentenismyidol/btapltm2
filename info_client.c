#include<stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netdb.h>
#include <string.h>
#include <arpa/inet.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
     if(argc != 3){
        printf("Sai tham so.\n");
        return 1;
    }
    char *ip = argv[1];
    char *host = argv[2];

    // khai bao socket
    int client = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    
    // khai bao dia chi server
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(ip);
    addr.sin_port = htons(atoi(host));
    if(inet_pton(AF_INET, ip, &addr.sin_addr) <= 0)  
    { 
        printf("Invalid address/ Address not supported \n"); 
        return -1; 
    }
    // int res = connect(client, (struct sockaddr *)&addr, sizeof(addr));
    
    // if (res<0)
    // {
    //     printf("Khong ket noi duoc voi server\n");
    //     return -1;
    }
    //gi du lieu den server
    char tenlaptop[256];
    int soOdia;
    unsigned short dungluong;
    char drive_letter;
    while(1) {
        printf("Nhap ten thiet bi");    
        //fgets(tenlaptop, sizeof(tenlaptop), stdin);
        scanf("%s",tenlaptop);
        // tenlaptop[strlen(tenlaptop) - 1] = 0;

        printf("\nNhap so luong o dia muon nhap dung luong:");
        //fgets(soOdia, sizeof(soOdia), stdin);
        scanf("%s",soOdia);

        //printf("%s",soOdia);
        for (int i = 0; i < soOdia; i++) {
            printf("\n nhap dung luong cho o %c - ",drive_letter);
            scanf("%hdGB", dungluong);
        }
    }

    // ket thuc, dong socket
    close(client);
    return 0;
}
