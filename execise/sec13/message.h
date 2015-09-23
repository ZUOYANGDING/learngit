#ifndef MESSAGE_H
#define MESSAGE_H

#include <iostream>
#include <string>
#include <set>

class Folder;

class Message
{
	friend class Folder;
	public:
		Message(const std::string&);
		Message(const Message&);
		Message& operator=(const Message&);
		void swap(Message&, Message&);
		void save(Folder&);
		void remove(Folder&);
		void print(ostream&);
		~Message();
	private:
		std::string content;
		std::set<Folder*> folder;
		void add_to_folder(const Message&);
		void delete_from_folder();
};

class Folder
{
	friend class Message;
	public:
		Folder(const std::string&);
		Folder(const Folder&);
		Folder& operator=(const Folder&);
		void swap(Folder&, Folder&);
		void add_msg(Message*);
		void rem_msg(Message*);
		void print(ostream&);
		~Folder()
	private:
		std::string name;
		std::set<Message*> meg_list;
};

#endif
