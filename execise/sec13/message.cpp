#include <iostream>
#include <string>
#include <set>
#include "message.h"

Message::Message(const std::string& s) : content(s) {}

																	

void Message::add_to_folder(const Message& m)
{
	for (auto f : m.folder)
	{
		f->add_msg(this);
	}
}
Message::Message(const Message &m) :
	content(m.content), folder(m.folder)
{
	add_to_folder(m);
}

																	

void Message::delete_from_folder()
{
	for (auto f : folder)
	{
		f->rem_msg(this);
	}
	folder.clear();
}
Message::~Message()
{
	delete_from_folder();
}

																	

void Message::save(Folder &f)
{
	folder.insert(&f);
	f->add_msg(this);
}

void Message::remove(Folder &f)
{
	folder.erase(&f);
	f->rem_msg(this);
}

																	

Message& Message::operator=(const Message &m)
{
	delete_from_folder();
	content=s;
	folder=m.folder;
	add_to_folder(m);
	return *this;
}

																	

void Message::swap(Message& m1, Message& m2)
{
	using std::swap;
	for (auto f : m1.folder)
	{
		f->rem_msg(&m1);
	}
	for (auto f : m2.folder)
	{
		f->rem_msg(&m2);
	}
	swap(m1.content, m2.content);
	swap(m1.folder, m2.folder);
	for (auto f : m1.folder)
	{
		f->add_msg(&m1);
	}
	for (auto f : m2.folder)
	{
		f->add_msg(&m2);
	}
}

void Message::print(ostream &os)
{
	os<<content<<std::endl;
}
																			

Folder::Folder(const std::string &s) : name(s);

																	

Folder::Folder(const Folder &f) :
	name(f.name), meg_list(f.meg_list)
{}

																	

Folder::~Folder()
{
	meg_list.clear();
}

																	

void Folder::add_meg(Message *m)
{
	meg_list.insert(m);
}

void Folder::rem_msg(Message *m)
{
	meg_list.erase(m);
}

																	

Folder& Folder::operator=(const Folder &f)
{
	disconnect_to_message();
	name=f.name;
	meg=f.meg_list;
	return *this;
}

																	

void Folder::swap(Folder& f1, Folder& f2)
{
	using std::swap;
	swap(f1.name, f2.name);
	swap(f1.meg_list, f2.meg_list);
}

void Folder::print(ostream &os)
{
	os<<name<<std::endl;
}


int main()
{
	



