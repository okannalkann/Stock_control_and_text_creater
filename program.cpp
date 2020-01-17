/* @Author
* Student Name: Okan Alkan
* Student ID : 150160803
* Date: 29.04.2019 */

#include <iostream>
#include <fstream>
# include<string>
#include <sstream>
#define MAX_MENU_SIZE 120

using namespace std;

class Table {
private:
	string table_name, table_order;
	int order_type, howManyOrder;
public:
	Table() { table_name = 'NULL'; order_type = 0; howManyOrder = 0; table_order = 'NULL'; };
	void TableOrder(string name, int order_count, string tables_order, int order_type);
	int checkCost(Table *t);
};

class Menu {
private:
	string dish_name, material;
	int gramaj, type;
public:
	friend class Table;
	Menu() { dish_name = "NULL"; material = "NULL"; gramaj = 0; type = 0; };
	void AddMenu(string yemek_adi, int adetgram, string materyal);
	void split_line(string satir, Menu *place);
};

class Stock {
private:
	string product_name;
	int type, itemCount;
	float price;
public:
	friend class Table;
	Stock() { product_name = 'NULL'; type = 0; itemCount = 0; price = 0; };
	void AddStock(string name, int product_type, int came_item, float product_price) {
		this->product_name = name;
		this->type = product_type;
		this->itemCount = came_item;
		this->price = product_price;
	}
	string get_product_name();
	int get_type();
	int get_itemCount();
	float get_price();
};
Stock *keeping_stock = new Stock[50];
Menu *Dmenu = new Menu[80];

int main()
{
	string temp, table, order_name, useless1, useless2, useless3, useless4, stockName, line, linetwo, lines, lines2, second_word, tempDishName;
	int Ordercount=0, howManyOrder, order_type, stockType, stockitemCount, count = 0, tableAdedi=0;
	float stockPrice;
	ifstream fin;
	ifstream file("stock.txt");
	while (getline(file, line)) // count stock lines
		count++;
	ifstream file2("order.txt");
	while (getline(file2, linetwo))
	{
		Ordercount++;
		if (linetwo[0] == 'T') // it will learn how many table in the order.txt
		{
			tableAdedi++;
		}
	}
	fin.open("stock.txt");	 //taking stock list
	fin >> useless1 >> useless2 >> useless3 >> useless4;
	for (int i = 0; i < count - 1; i++) // We assign all the materials in stock.txt to an object.
	{
		fin >> stockName >> second_word;
		if (second_word == "1" || second_word == "2" || second_word == "3" || second_word == "4") {
			stringstream ss(second_word);
			int strAsInt;
			ss >> strAsInt;
			stockType = strAsInt;
		}
		else {
			stockName = stockName + " " + second_word;
			fin >> stockType;
		}
		fin >> stockitemCount >> stockPrice;
		keeping_stock[i].AddStock(stockName, stockType, stockitemCount, stockPrice); // adding material to the stock 
	}
	fin.clear();
	fin.close();
	fin.open("menu.txt");
	while (getline(fin, lines, '\n')) //We assign all the materials in menu.txt to an object.
	{
		Dmenu->split_line(lines, Dmenu); //We have sent the incoming line to the function that divides it into pieces and adds them to the object.
	}
	fin.clear();
	fin.close();
	fin.open("order.txt");
	int tempo = 0,tempo2=0,tempo3=0,tempo4=0,tempo5=0;
	//table1
	fin >> table >> howManyOrder;
	tempo = howManyOrder;
	if (Ordercount > (howManyOrder + 2) && tableAdedi >= 1) // There are 5 tables in the restaurant
	{									// the order txt is also checking the 5 tables if the table is empty does not print the message.
		Table *table1 = new Table[howManyOrder + 2];
		cout << table << " ordered:" << endl;
		for (int i = 1; i <= howManyOrder; i++)
		{
			fin >> order_type;
			getline(fin, lines, '\n');
			order_name = lines;
			table1[i].TableOrder(table, howManyOrder, order_name, order_type); // Adds orders on the table to the object.
		}
		table1->checkCost(table1);
		cout << "**************************" << endl;
		delete[] table1;
	}
	if (Ordercount > (howManyOrder + 2 + tempo) && tableAdedi >= 2) //if table2 exist it is works 
	{									
		//table2
		fin >> table >> howManyOrder;
		tempo2 = howManyOrder;
		cout << table << " ordered:" << endl;
		Table *table2 = new Table[howManyOrder + 2];
		for (int i = 1; i <= howManyOrder; i++)
		{
			fin >> order_type;
			getline(fin, lines, '\n');
			order_name = lines;
			table2[i].TableOrder(table, howManyOrder, order_name, order_type); //Adds orders on the table to the object.
		}
		table2->checkCost(table2);
		cout << "**************************" << endl;
		delete[] table2;
	}
	if (Ordercount > (howManyOrder + 2 + tempo + tempo2) && tableAdedi >=3)//if table3 exist it is works 
	{								
		//table3
		fin >> table >> howManyOrder;
		tempo3 = howManyOrder;
		cout << table << " ordered:" << endl;
		Table *table3 = new Table[howManyOrder + 2];
		for (int i = 1; i <= howManyOrder; i++)
		{
			fin >> order_type;
			getline(fin, lines, '\n');
			order_name = lines;
			table3[i].TableOrder(table, howManyOrder, order_name, order_type); //Adds orders on the table to the object.
		}
		table3->checkCost(table3);
		cout << "**************************" << endl;
		delete[] table3;
	}
	if (Ordercount > (howManyOrder + 2 + tempo + tempo2 + tempo3) && tableAdedi >= 4)  // if table4 exist it will work
	{												
		//table4
		fin >> table >> howManyOrder;
		tempo4 = howManyOrder;
		cout << table << " ordered:" << endl;
		Table *table4 = new Table[howManyOrder + 2];
		for (int i = 1; i <= howManyOrder; i++)
		{
			fin >> order_type;
			getline(fin, lines, '\n');
			order_name = lines;
			table4[i].TableOrder(table, howManyOrder, order_name, order_type); //Adds orders on the table to the object.
		}
		table4->checkCost(table4);
		cout << "**************************" << endl;
		delete[] table4;
	}
	if (Ordercount > (howManyOrder + 2 + tempo + tempo2 + tempo3 + tempo4) && tableAdedi >= 5) // if order.txt have the table5 it will work
	{														
		//table5
		fin >> table >> howManyOrder;
		cout << table << " ordered:" << endl;
		Table *table5 = new Table[howManyOrder + 2];
		for (int i = 1; i <= howManyOrder; i++)
		{
			fin >> order_type;
			getline(fin, lines, '\n');
			order_name = lines;
			table5[i].TableOrder(table, howManyOrder, order_name, order_type); // Adds orders on the table to the object.
		}
		table5->checkCost(table5);
		cout << "**************************" << endl;
		delete[] table5;
	}

	ofstream myfile; // update stock.txt
	myfile.open("stock.txt");
	myfile << "Name\t" << "Type\t" << "ItemCount\t" << "Price\n";
	for (int i = 0; i < count - 1; i++) {
		myfile << keeping_stock[i].get_product_name() << "\t" << keeping_stock[i].get_type() << "\t" << keeping_stock[i].get_itemCount() << "\t" << keeping_stock[i].get_price() << "\n";
	}
	myfile.close();
	delete[] keeping_stock; // free memory
	delete[] Dmenu; // free memory
	return 0;
}

void Table::TableOrder(string name, int order_count, string tables_order, int order_type) //add table orders to the object.
{
	this->howManyOrder = order_count;
	this->table_name = name;
	this->table_order = tables_order;
	this->order_type = order_type;
}

int Table::checkCost(Table *t)
{
	bool donthave = false, firsttimeEver = true, printfirst=true;
	double price, cost=0, tempcost =0;
	int gg = 1, pp;
	for (int i = 1; i <= t[i].howManyOrder; i++) // how many orders it takes
	{
		t[i].table_order = t[i].table_order.erase(0, 1);  // lines are deleted at the beginning of the lines in the txt file to delete it.
		for (int k = 1; k <= t[i].order_type; k++)// checks how many of an order.
		{
			while (t[i].table_order != Dmenu[gg].dish_name) // food names control
				gg++;

			if(t[i].table_order == Dmenu[gg].dish_name) //material control
			{
				for (int mk = 0; mk < 25; mk++) //stock control
				{
					if ((Dmenu[gg].material == keeping_stock[mk].product_name) && (t[i].table_order == Dmenu[gg].dish_name)) //Is material available in stock
					{
						if (Dmenu[gg].gramaj <= keeping_stock[mk].itemCount) //Does the material have enough of its control
						{
							cost += Dmenu[gg].gramaj * keeping_stock[mk].price;
							keeping_stock[mk].itemCount -= Dmenu[gg].gramaj; // stock object updated
							gg++;
							mk = -1;
						}
						else
						{
							donthave = true; //If you do not have enough to eat you have to check for the error message.
						}
					}
				}
				if(firsttimeEver==false) 
				tempcost = cost - tempcost;
			}
			pp = gg;
			gg = 1;
		}	
		if (donthave == true)
		{
			cout << "We don't have enough " << Dmenu[pp].dish_name << endl;
			donthave = false;
		}
		else
		{
			if (printfirst == true) // print the dishes cost 
			{
				cout << t[i].order_type << " " << t[i].table_order << " cost: " << cost << endl;
				printfirst = false;
			}
			else
			{
				cout << t[i].order_type << " " << t[i].table_order << " cost: " << tempcost << endl;
			}
			
		}
		tempcost = cost;
		firsttimeEver = false;
	}
	price = cost + (cost*0.08) + (cost*0.15);
//	cout << "tx = " << cost * 0.08 << "tp = " << cost *0.15;
	cout << "Tip is " << cost * 0.15 << endl;
	cout << "Total cost: " << price << " TL" << endl;
	return price;
}

bool firstline = true;
void Menu::AddMenu(string yemek_adi, int adetgram, string materyal)
{
	this->dish_name = yemek_adi;
	this->gramaj = adetgram;
	this->material = materyal;
}
int k = 1;
void Menu::split_line(string satir, Menu *place)
{
	bool first = false, kaan = false, eney = false;
	string parsed, input = satir, dishname, ba, bb,temp, temp2, temp3;
	int mur = 0, rum = 0, yarkin = 0, a = 0;
	stringstream input_stringstream(input);
	if (firstline==true)
	{
		input_stringstream >> ba >> bb; // it is taking Name Ingredeants line
		firstline = false;
	}
	else {
		getline(input_stringstream, parsed, '\t'); // placing the line into the object by placing it in the mold properly.
		dishname = parsed;
		while (getline(input_stringstream, parsed, '\t'))   // placing the line into the object by placing it in the mold properly.
		{
			string parsed2, input2 = parsed;
			stringstream input_stringstream2(input2);
			while (getline(input_stringstream2, parsed2, ',')) // placing the line into the object by placing it in the mold properly.
			{
				if (kaan == true)
				{
					parsed2.erase(0, 1);
				}
				string parsed3, input3 = parsed2;
				stringstream input_stringstream3(input3);
				while (getline(input_stringstream3, parsed3, ' ')) // placing the line into the object by placing it in the mold properly.
				{
					if (parsed3 == "N/A")
					{
						temp2 = "2";
						temp = "1";
						temp3 = dishname;
					}	
					else if (rum == 0 && mur == 0)
					{
						temp = parsed3;
						rum++;
					}
					else if (rum == 1 && mur == 0)
					{
						if (parsed3 != "gram" && parsed3 != "ml")
						{
							temp2 = "2";
							temp3 = parsed3;
							first = true;
						}
						else
						{
							if (parsed3 == "gram")
								temp2 = "1";
							if (parsed3 == "ml")
								temp2 = "3";
						}
						rum++;
					}
					else if (rum > 1 && mur == 0)
					{
						if (first == false)
						{
							temp3 = parsed3;
							first = true;
						}
						else
						{
							temp3 = temp3 + " " + parsed3;
						}
					}
					kaan = true;
					//second part
					if (rum == 0 && mur == 1)
					{
						temp = parsed3;
						rum++;
					}
					else if (rum == 1 && mur == 1)
					{
						if (parsed3 != "gram" && parsed3 != "ml")
						{
							temp2 = "2";
							temp3 = parsed3;
							first = true;
						}
						else
						{
							if (parsed3 == "gram")
								temp2 = "1";
							if (parsed3 == "ml")
								temp2 = "3";
						}
						rum++;
					}
					else if (rum > 1 && mur == 1)
					{
						if (first == false)
						{
							temp3 = parsed3;
							first = true;
						}
						else
						{
							temp3 = temp3 + " " + parsed3;
						}
					}
				}
				if (eney != true)
				{
					place[k].dish_name = dishname; //places parsed lines
					a = stoi(temp);					
					place[k].gramaj = a; //places parsed lines
					place[k].type = stoi(temp2); //places parsed lines
					place[k].material = temp3;// places parsed lines
					k++;
					eney = false;
				}
				temp3 = "";
				rum = 0;
				mur = 1;
				first = false;
			}
			eney = false;
			kaan = false;
		}
	}
}

string Stock::get_product_name()
{
	return product_name;
}

int Stock::get_type()
{
	return type;
}

int Stock::get_itemCount()
{
	return itemCount;
}

float Stock::get_price()
{
	return price;
}
