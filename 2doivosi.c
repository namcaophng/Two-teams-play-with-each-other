#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
struct Monphai{
    char biethieu[30], mp[20];
    int tancong, nhanhnhen, phongthu, mau, point, stt;
};
main(){
    struct Monphai mp1[50], mp2[50], dt1, dt2, total[100];
    int i=0, turn, j, n1, n2, n11, n22, dem=0, l1, l2;
    char bt[20];
    for (i=0; i<50; ++i){
        mp1[i].mau=0;mp2[i].mau=0;
    }
    FILE *f;
    f = fopen("mp1.txt","r");
    for (i=1; i<50; ++i){
        fscanf(f, "%s", &mp1[i].biethieu);
        fscanf(f, "%d", &mp1[i].mau);
        fscanf(f, "%d", &mp1[i].tancong);
        fscanf(f, "%d", &mp1[i].nhanhnhen);
        fscanf(f, "%d", &mp1[i].phongthu);
        if(mp1[i].mau==0) break;
        dem++;
    }
    n1=dem; n11=dem; dem=0;
    fclose(f);
    for(i=1; i<=n1; ++i){
        strcpy(total[i].mp, "Mon phai 1");
        strcpy(total[i].biethieu, mp1[i].biethieu);
        total[i].point = 0;
    }
    f = fopen("mp2.txt", "r");
    for (i=1; i<50; ++i){
        fscanf(f, "%s", &mp2[i].biethieu);
        fscanf(f, "%d", &mp2[i].mau);
        fscanf(f, "%d", &mp2[i].tancong);
        fscanf(f, "%d", &mp2[i].nhanhnhen);
        fscanf(f, "%d", &mp2[i].phongthu);
        if(mp2[i].mau==0) break;
        dem++;
    }
    n2=dem; n22=dem; dem=0;
    for(i=n1+1; i<=n1+n2; ++i){
        strcpy(total[i].mp, "Mon phai 2");
        strcpy(total[i].biethieu, mp2[i-n1].biethieu);
        total[i].point = 0;
    }
    fclose(f);
    printf("\nMon phai 1 co: %d vo si",n1);
    printf("\nMon phai 2 co: %d vo si",n2);
    strcpy(dt1.biethieu, mp1[1].biethieu);
    dt1.mau=mp1[1].mau;
    dt1.tancong=mp1[1].tancong;
    dt1.nhanhnhen=mp1[1].nhanhnhen;
    dt1.phongthu=mp1[1].phongthu;
    l1=1;
    strcpy(dt2.biethieu, mp2[1].biethieu);
    dt2.mau=mp2[1].mau;
    dt2.tancong=mp2[1].tancong;
    dt2.nhanhnhen=mp2[1].nhanhnhen;
    dt2.phongthu=mp2[1].phongthu;
    l2=n11+1;
    while(n1>=0&&n2>=0){
        if(dt1.mau<=0){
            for (i=1; i<n1; ++i){
                strcpy(mp1[i].biethieu, mp1[i+1].biethieu);
                mp1[i].mau=mp1[i+1].mau;
                mp1[i].tancong=mp1[i+1].tancong;
                mp1[i].nhanhnhen=mp1[i+1].nhanhnhen;
                mp1[i].phongthu=mp1[i+1].phongthu;
            }
            --n1;
            strcpy(dt1.biethieu, mp1[1].biethieu);
            dt1.mau=mp1[1].mau;
            dt1.tancong=mp1[1].tancong;
            dt1.nhanhnhen=mp1[1].nhanhnhen;
            dt1.phongthu=mp1[1].phongthu;
            ++l1;
        }
        if (dt2.mau<=0){
            for (i=1; i<n2; ++i){
                strcpy(mp2[i].biethieu, mp2[i+1].biethieu);
                mp2[i].mau=mp2[i+1].mau;
                mp2[i].tancong=mp2[i+1].tancong;
                mp2[i].nhanhnhen=mp2[i+1].nhanhnhen;
                mp2[i].phongthu=mp2[i+1].phongthu;
            }
            --n2;
            strcpy(dt2.biethieu, mp2[1].biethieu);
            dt2.mau=mp2[1].mau;
            dt2.tancong=mp2[1].tancong;
            dt2.nhanhnhen=mp2[1].nhanhnhen;
            dt2.phongthu=mp2[1].phongthu;
            ++l2;
        }
        if(n1<0){
            printf("\nMon phai thu 2 gianh chien thang chung cuoc");
            break;
        }
        if(n2<0){
            printf("\nMon phai thu 1 gianh chien thang chung cuoc");
            break;
        }
        if (dt1.nhanhnhen>=dt2.nhanhnhen) turn=1;
        else turn=-1;
        printf("\nCUOC SO TAI CUA DOI THU %s VA %s:",dt1.biethieu, dt2.biethieu);
        while(dt1.mau>0&&dt2.mau>0){
            if(turn==1){
                printf("\n%s ra don vao %s lay di %d mau",dt1.biethieu, dt2.biethieu, dt1.tancong-dt2.phongthu);
                dt2.mau -= (dt1.tancong-dt2.phongthu);++dem;
                ++total[l1].point;
            }
            if(turn==-1){
                printf("\n%s ra don vao %s lay di %d mau",dt2.biethieu, dt1.biethieu, dt2.tancong-dt1.phongthu);
                dt1.mau -= (dt2.tancong-dt1.phongthu);++dem;
                ++total[l2].point;
            }
            turn=-turn;
            if(dt1.mau<=0){
                if(dem==1){
                    printf("\n%s da KNOCKOUT %s",dt2.biethieu, dt1.biethieu);
                    total[l2].point +=2;
                }
                else printf("\n%s da chien thang %s",dt2.biethieu, dt1.biethieu);
            }
            if(dt2.mau<=0){
                if(dem==1){
                    printf("\n%s da KNOCKOUT %s",dt1.biethieu, dt2.biethieu);
                    total[l1].point +=2;
                }
                else printf("\n%s da chien thang %s",dt1.biethieu, dt2.biethieu);
            }
        }
        dem=0;
    }
    for(i=1; i<n11+n22; ++i){
        for(j=1; j<=n11+n22-i; ++j){
            if (total[j].point < total[j+1].point){
                dem = total[j].point;
                total[j].point = total[j+1].point;
                total[j+1].point = dem;
                strcpy(bt, total[j].biethieu);
                strcpy(total[j].biethieu, total[j+1].biethieu);
                strcpy(total[j+1].biethieu, bt);
                strcpy(bt, total[j].mp);
                strcpy(total[j].mp, total[j+1].mp);
                strcpy(total[j+1].mp, bt);
            }
        }
    }
    printf("\n\nBang xep hang cac vo si");
    for (i=1; i<=n11+n22; ++i){
        printf("\n%d. Vo si \"%s\" den tu %s voi so diem %d", i, total[i].biethieu, total[i].mp, total[i].point);
    }
    getch();
}
