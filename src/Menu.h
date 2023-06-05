//
// Created by Leo on 11.04.2023.
//

#ifndef GDS1PORSCHEMUEHK_MENU_H
#define GDS1PORSCHEMUEHK_MENU_H

class Navigator;

class Menu {
    String itemName[10];
    void(*itemFunction[10])(Navigator*, uint8_t);
    uint8_t itemFunctionIndex[10];
    uint8_t itemCount = 0;

    Navigator *navigator;

public:
    Menu(Navigator *navigator);
    uint8_t getItemCount() const;
    String getName(uint8_t index);

    void addItem(const String &name, void (*function)(Navigator*, uint8_t)=nullptr, uint8_t index=0);

    void executeFunction(uint8_t itemIndex);
};


#endif //GDS1PORSCHEMUEHK_MENU_H
