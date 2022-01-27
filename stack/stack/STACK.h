#pragma once
struct Book
{
	Book* l;
	int page_count;
	char* name;
	int signal_un;
	union
	{
		char a_name[20];
		int  volume_count;
	};
};
Book* push(Book* s);
void show(Book* s);
Book* deleteALL(Book*);
void search(struct Book* s);
void save(struct Book* s);
Book* read(Book* h);
Book* reverse(Book* s);