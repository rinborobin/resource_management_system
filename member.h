#ifndef MEMBER_H
#define MEMBER_H

#include "data.h"

void memberMenu(Library *lib);
void addMember(Library *lib);
void viewMembers(Library *lib);
void updateMember(Library *lib);
void removeMember(Library *lib);
int searchMember(Library *lib, int member_id);

#endif // !MEMBER_H
