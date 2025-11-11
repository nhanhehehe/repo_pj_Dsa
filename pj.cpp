#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>
#define ll long long
#include <iomanip>
using namespace std;

vector<string> idArchieve; // luu tru ma nhan vien 

struct employee
{
   string id;
   string name;
   string position;
   int year;
   string manager;
};

struct Node
{
   int data1;
   employee data;
   Node *next;
   vector<Node *> children;
};

vector<Node *> employeeWaiting; // danh sach nhan vien k chinh thuc

Node *createNode(employee nv)
{
   Node *temp = new Node;
   temp->data = nv;
   temp->next = NULL;
   return temp;
}

struct List
{
   Node *first;
   Node *last;
};

void createList(List &l)
{
   l.first = NULL;
   l.last = NULL;
}

// tao nhan vien ( employee date cua Node)
employee createEmployee()
{
   employee nv;
   cout << "=== Nhap thong tin nhan vien moi ===\n";
   cout << "Nhap ma id: ";
   string id;
   while (true) {
      int flag = 1;
      cin >> id;
      for (auto x : idArchieve) {
         if (x == id) {
            cout << "Ma nhan vien da ton tai!\n";
            cout << "nhap lai: "; 
            flag = 0;
            break;    
         }
      }
      if (flag) {
         nv.id = id;
         idArchieve.push_back(id);
         break;
      }
   }
   cout << "Nhap ten: ";
   cin.ignore();
   getline(cin, nv.name);
   cout << "Nhap vi tri: ";
   getline(cin, nv.position);
   cout << "Nhap nam lam viec: ";
   cin >> nv.year;
   cout << "Nhap ma quan ly: ";
   cin >> nv.manager;
   cout << endl << endl;
   return nv;
}

// them node vao sau
// void InsertNode(List &l)
// {
//    Node *nv = createNode(createEmployee());
//
//    if (l.first == NULL)
//    {
//       l.first = nv;
//       l.last = nv;
//    }
//    else
//    {
//       l.last->next = nv;
//       l.last = nv;
//    }
// }




// ============================ chuc nang 1 ============================
// tim nhan vien ban id
Node *SearchID(Node *root, string id)
{
   if (root == NULL)
      return NULL;
   if (root->data.id == id)
      return root;

   for (Node *child : root->children)
   {
      Node *found = SearchID(child, id);
      if (found)
         return found;
   }
   return NULL;
}

// them moi nhan vien
void InsertEmployee(List& l, employee nv)
{
   
   if (l.first == NULL)
   {  
      //them giam doc
      l.first = createNode(nv);
      cout << "them giam doc thanh cong!\n ";
      return;
   }

   Node *manager = SearchID(l.first, nv.manager);
   if (manager == NULL) {
      employeeWaiting.push_back(createNode(nv));
      cout << "Them nhan vien khong chinh thuc moi\n\n ";
      return;
   }

   Node *newEmployee = createNode(nv);
   manager->children.push_back(newEmployee);
   cout << "Them nhan vien thanh cong! " << endl << endl;
}

//chuc nang 1
void Function1(List& l) {
   employee newEmployee = createEmployee();
   InsertEmployee(l, newEmployee);
}
// ============================================================


//============================================

void printOrg(Node *root, int level = 0)
{

   if (root == nullptr)
      return;
   // cout << "-------------------------------------------------------------------------------------------------------------\n";
   // cout << right << setw(80) << "===== CAU TRUC DOANH NGHIEP  =====\n\n";
   
   for (int i = 0; i < level; i++)
      cout << '\t';

   cout << "- " << root->data.id << " | " << root->data.name << " | " << root->data.position << " | " << root->data.year << " | " << root->data.manager << endl;

   for (auto child : root->children)
   {
      printOrg(child, level + 1);
   }
   // cout << "-------------------------------------------------------------------------------------------------------------\n\n";
}

void printUnOF(vector<Node *> ds) {
   cout << endl;
   cout << "Danh sach nhan vien khong chinh thuc:\n";
   for (auto x : ds) {
      cout << "- " << x->data.id << " | " << x->data.name << " | " << x->data.position << " | " << x->data.year << " | " << x->data.manager << endl;
   }
}

//===========================================


// menu chuc nang
void Menu(List& l)
{
   while (true)
   {
      cout << "-------------------------------------------------------------------------------------------------------------\n";
      cout << right << setw(70) << "=====  QUAN LY TO CHUC DOANH NGHIEP  =====\n";
      cout << "1. Them nhan vien\n";
      cout << "2. Xoa nhan vien\n";
      cout << "3. Cap nhat thong tin nhan vien\n";
      cout << "4. Hien thi so do to chuc\n";
      cout << "5. Tim nhan vien theo ID\n";
      cout << "6. Tim nhan vien theo Ten\n";
      cout << "7. Luu du lieu ra file\n";
      cout << "8. Tai du lieu tu file\n";
      cout << "0. Thoat\n";
      cout << "-------------------------------------------------------------------------------------------------------------\n";
      cout << "Nhap lua chon: ";
      int t; cin >> t;
      cout << endl << endl;
      switch (t) {
         case 0:
         {
            cout << "Thoat chuong trinh ...";
            return;
         }
         case 1:
         {
            Function1(l);
            break;
         }
         case 2:
         {
            
         }
         case 3:
         {
            
         }
         case 4:
         {  
            cout << "Danh sach nhan vien chinh thuc\n";
            printOrg(l.first);
            printUnOF(employeeWaiting);
            break;

         }
         case 5:
         {
            
         }
         case 6:
         {
            
         }
         case 7:
         {
            
         }
         case 8:
         {
            
         }
         default:
         {
            cout << "!lua chon khong hop le!\n";
            cout << "vui long chon lai\n";
         }
      }
      
   }
}

int main()
{
   List l;
   createList(l);
   Menu(l);
}