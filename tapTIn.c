#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    int MaSach;
    char TenSach[50];
    int SoLuong;
} Sach;

typedef struct Node
{
    Sach data;
    struct Node *next;
} Node;

Node *first = NULL;

Node *capPhatNode()
{
    Node *node = (Node *)malloc(sizeof(Node));
    return node;
}

Sach nhapThongTin()
{
    Sach sach;
    printf("Nhap ma sach:");
    scanf("%d", &sach.MaSach);
    printf("Nhap ten sach:");
    fflush(stdin);
    gets(sach.TenSach);
    printf("Nhap so luong:");
    scanf("%d", &sach.SoLuong);
    fflush(stdin);
    return sach;
}

Node *taoVaNhapNode()
{
    Node *node = capPhatNode();
    node->data = nhapThongTin();
    node->next = NULL;
    return node;
}

void themPhanTuDauTien(Node *node)
{
    first = node;
}

Node *timNodeCuoi()
{
    Node *last = first;
    while (last->next != NULL)
    {
        last = last->next;
    }
    return last;
}

void themPhanTuViTriCuoi(Node *node)
{
    if (first == NULL)
    {
        themPhanTuDauTien(node);
    }
    else
    {
        Node *last = timNodeCuoi();
        last->next = node;
    }
}

Node *timNodeTheoTen(char tenSach[])
{
    Node *node = first;
    while (strcmp(node->next->data.TenSach, tenSach) != 0)
    {
        node = node->next;
    }
    return node;
}

void themPhanTuSauMotPhanTu(Node *newnode, char tenSach[])
{
    Node *node = timNodeTheoTen(tenSach);
    newnode->next = node->next;
    node->next = newnode;
}

void xoaNode(char tenSach[])
{
    Node *delnode = timNodeTheoTen(tenSach);
    if (delnode == first)
    {
        first = first->next;
        free(delnode);
        return;
    }

    Node *node = first;
    while (node->next != delnode)
    {
        node = node->next;
    }
    node->next = delnode->next;
    free(delnode);
}

void hienThiDanhSachTheoDong(Sach data, int stt)
{
    printf("%-8d%-11d%-12s%-12d\n", stt, data.MaSach, data.TenSach, data.SoLuong);
}

void hienThiDanhSach()
{
    int stt = 1;
    printf("\tDANH SACH SACH\nSTT      MASACH     TENSACH     SOLUONG\n");
    for (Node *i = first; i != NULL; i = i->next)
    {
        hienThiDanhSachTheoDong(i->data, stt++);
    }
}

void inMenu()
{
    printf("1.Tao danh sach sachn\n");
    printf("2.Hien thi danh sach\n");
    printf("3.Them mot cuon sach\n");
    printf("4.Xoa mot cuon sach\n");
    printf("0.Thoat\n");
}

int main()
{
    int a = 1;
    while (1)
    {
        inMenu();
        int chon;
        scanf("%d", &chon);
        switch (chon)
        {
        case 1:
        {
            while (1)
            {
                printf("Nhap cuon sach thu %d\n", a++);
                themPhanTuViTriCuoi(taoVaNhapNode());
                printf("\nNhan 't' de nhap tiep\n");
                char x;

                scanf("%c", &x);
                if (x != 't')
                {
                    break;
                }
            }
            break;
        }
        case 2:
        {
            hienThiDanhSach();
            break;
        }
        case 3:
        {
            printf("Them vao sau cuon sach co ten:\n");
            char tenSach[50];
            fflush(stdin);
            gets(tenSach);
            printf("Nhap cuon sach muon them:\n");
            themPhanTuSauMotPhanTu(taoVaNhapNode(), tenSach);
            break;
        }
        case 4:
        {
            printf("Nhap ten phan tu muon xoa:\n");
            char tenSach[50];
            fflush(stdin);
            gets(tenSach);
            xoaNode(tenSach);
            break;
        }
        case 0:
        {
            printf("tam biet!\n");
            break;
        }
        }
    }
}