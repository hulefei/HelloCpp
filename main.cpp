#include <iostream>
#include "Sales_data.h"
#include "Window_mgr.h"

//读写SalesData
void rwSalesData();
//操作类
void OperateWindow();

int main() {
    std::cout << "Hello, main!" << std::endl;

//    Sales_data salesData;
//    salesData.to_string();

    OperateWindow();

    return 0;
}

void rwSalesData()
{
    std::cout << "rwSaleSData ======================" << std::endl;
    Sales_data item;
    read(std::cin, item);
    print(std::cout, item);
    std::cout << "rwSaleSData ======================" << std::endl;
}

void OperateWindow() {
    Window_mgr windowMgr;

    auto count = windowMgr.screenCount();
    std::cout << "count:" << count << std::endl;

//    auto screen = windowMgr.getScreen(0);
//    screen.set(0, 2, 'a');
//    screen.display(std::cout);

    Screen screen1;
    screen1.set(0, 1, 'b');
    auto index1 = windowMgr.addScreen(screen1);
    std::cout << "index2:" << index1 << std::endl;
    auto screen_1 = windowMgr.getScreen(index1);
    screen_1.display(std::cout);
}
