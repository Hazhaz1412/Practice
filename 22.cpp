#include <iostream>
#include <string>
#include <ctime>
using namespace std;

struct Passenger {
    string name;
    string phone;
    time_t notifyTime = 0;
};

struct Node {
    Passenger* data;
    Node* next = nullptr;
};

struct Queue {
    Node* head = nullptr;
    Node* tail = nullptr;
    int count = 0;
    
    ~Queue() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp->data;
            delete temp;
        }
    }
    
    void enqueue(Passenger* p) {
        Node* newNode = new Node{p};
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        count++;
    }
    
    Passenger* dequeue() {
        if (head == nullptr) return nullptr;
        
        Node* temp = head;
        Passenger* p = temp->data;
        head = head->next;
        
        if (head == nullptr) tail = nullptr;
        
        delete temp;
        count--;
        return p;
    }
    
    Passenger* peek() {
        return (head == nullptr) ? nullptr : head->data;
    }
    
    bool isEmpty() {
        return head == nullptr;
    }
    
    int size() {
        return count;
    }
};

struct Bus {
    string routeId;
    string departureTime;
    int totalSeats;
    int availableSeats;
    Passenger** seats;
    Queue waitingList;
    int timeLimit;
    
    Bus(string id, string time, int seatCount, int limit) {
        routeId = id;
        departureTime = time;
        totalSeats = seatCount;
        availableSeats = seatCount;
        timeLimit = limit;
        
        seats = new Passenger*[totalSeats];
        for (int i = 0; i < totalSeats; i++) {
            seats[i] = nullptr;
        }
    }
    
    ~Bus() {
        for (int i = 0; i < totalSeats; i++) {
            if (seats[i] != nullptr) {
                delete seats[i];
            }
        }
        delete[] seats;
    }
    
    int bookTicket(string name, string phone) {
        Passenger* p = new Passenger{name, phone, 0};
        
        if (availableSeats > 0) {
            for (int i = 0; i < totalSeats; i++) {
                if (seats[i] == nullptr) {
                    seats[i] = p;
                    availableSeats--;
                    cout << "Đặt vé thành công cho " << name << " tại ghế " << i+1 << endl;
                    return i+1;
                }
            }
        } else {
            waitingList.enqueue(p);
            cout << name << " đã được đưa vào danh sách chờ ở vị trí " << waitingList.size() << endl;
            return -waitingList.size();
        }
        return 0;
    }
    
    bool cancelTicket(int seatNumber) {
        if (seatNumber < 1 || seatNumber > totalSeats) {
            cout << "Số ghế không hợp lệ!" << endl;
            return false;
        }
        
        int index = seatNumber - 1;
        if (seats[index] == nullptr) {
            cout << "Ghế này chưa được đặt!" << endl;
            return false;
        }
        
        cout << "Đã hủy vé cho " << seats[index]->name << " tại ghế " << seatNumber << endl;
        delete seats[index];
        seats[index] = nullptr;
        availableSeats++;
        
        checkWaitingList();
        return true;
    }
    
    void checkWaitingList() {
        if (!waitingList.isEmpty() && availableSeats > 0) {
            Passenger* next = waitingList.peek();
            next->notifyTime = time(nullptr);
            
            cout << "Thông báo cho " << next->name << " (" << next->phone 
                 << ") về chỗ trống. Cần xác nhận trong " << timeLimit << " giây." << endl;
        }
    }
    
    bool confirmTicket(string name) {
        if (waitingList.isEmpty() || availableSeats <= 0) {
            cout << "Không có yêu cầu xác nhận nào!" << endl;
            return false;
        }
        
        Passenger* next = waitingList.peek();
        if (next->name != name) {
            cout << "Không đúng tên người được thông báo!" << endl;
            return false;
        }
        
        time_t now = time(nullptr);
        if (now - next->notifyTime > timeLimit) {
            cout << "Đã hết thời gian xác nhận!" << endl;
            skipCurrentWaiting();
            return false;
        }
        
        next = waitingList.dequeue();
        
        for (int i = 0; i < totalSeats; i++) {
            if (seats[i] == nullptr) {
                seats[i] = next;
                availableSeats--;
                cout << "Đã xác nhận vé cho " << next->name << " tại ghế " << i+1 << endl;
                return true;
            }
        }
        
        return false;
    }
    
    void skipCurrentWaiting() {
        if (!waitingList.isEmpty()) {
            Passenger* skipped = waitingList.dequeue();
            cout << "Đã bỏ qua " << skipped->name << " do quá thời gian xác nhận" << endl;
            delete skipped;
            
            checkWaitingList();
        }
    }
    
    void checkExpiredConfirmations() {
        if (waitingList.isEmpty() || availableSeats <= 0) {
            return;
        }
        
        Passenger* next = waitingList.peek();
        if (next->notifyTime > 0) {
            time_t now = time(nullptr);
            if (now - next->notifyTime > timeLimit) {
                cout << "Hết hạn xác nhận cho " << next->name << endl;
                skipCurrentWaiting();
            }
        }
    }
    
    void displayInfo() {
        cout << "\n===== THÔNG TIN TUYẾN XE =====" << endl;
        cout << "Mã tuyến: " << routeId << endl;
        cout << "Thời gian khởi hành: " << departureTime << endl;
        cout << "Tổng số ghế: " << totalSeats << endl;
        cout << "Số ghế còn trống: " << availableSeats << endl;
        
        cout << "\nDanh sách hành khách:" << endl;
        for (int i = 0; i < totalSeats; i++) {
            if (seats[i] != nullptr) {
                cout << "Ghế " << i+1 << ": " << seats[i]->name << " - " << seats[i]->phone << endl;
            }
        }
        
        cout << "\nSố người trong danh sách chờ: " << waitingList.size() << endl;
    }
};

// Giữ nguyên linked list cho hệ thống xe
struct BusNode {
    Bus* data;
    BusNode* next = nullptr;
};

struct TicketSystem {
    BusNode* busList = nullptr;
    
    ~TicketSystem() {
        while (busList != nullptr) {
            BusNode* temp = busList;
            busList = busList->next;
            delete temp->data;
            delete temp;
        }
    }
    
    void addBus(string id, string time, int seats, int timeLimit) {
        Bus* newBus = new Bus(id, time, seats, timeLimit);
        BusNode* newNode = new BusNode{newBus};
        
        if (busList == nullptr) {
            busList = newNode;
        } else {
            newNode->next = busList;
            busList = newNode;
        }
        
        cout << "Đã thêm tuyến xe " << id << endl;
    }
    
    Bus* findBus(string id) {
        BusNode* current = busList;
        while (current != nullptr) {
            if (current->data->routeId == id) {
                return current->data;
            }
            current = current->next;
        }
        return nullptr;
    }
    
    void checkAllExpiredConfirmations() {
        BusNode* current = busList;
        while (current != nullptr) {
            current->data->checkExpiredConfirmations();
            current = current->next;
        }
    }
    
    void displayAllBuses() {
        BusNode* current = busList;
        if (current == nullptr) {
            cout << "Không có tuyến xe nào!" << endl;
            return;
        }
        
        while (current != nullptr) {
            current->data->displayInfo();
            current = current->next;
        }
    }
};

int main() {
    TicketSystem system;
    int choice;
    string busId, name, phone;
    int seatNumber, seats, timeLimit;
    string departureTime;
    
    time_t lastCheckTime = std::time(nullptr);
    
    system.addBus("HN-SG", "08:00", 3, 60);
    system.addBus("HN-HP", "10:00", 1, 60);
    
    while (true) {
        time_t currentTime = std::time(nullptr);
        if (currentTime - lastCheckTime >= 5) {
            system.checkAllExpiredConfirmations();
            lastCheckTime = currentTime;
        }
        
        cout << "\n===== HỆ THỐNG ĐẶT VÉ XE =====" << endl;
        cout << "1. Thêm tuyến xe mới" << endl;
        cout << "2. Đặt vé" << endl;
        cout << "3. Hủy vé" << endl;
        cout << "4. Xác nhận vé từ danh sách chờ" << endl;
        cout << "5. Hiển thị thông tin tuyến xe" << endl;
        cout << "6. Hiển thị tất cả tuyến xe" << endl;
        cout << "7. Kiểm tra hết hạn xác nhận" << endl;
        cout << "0. Thoát" << endl;
        cout << "Lựa chọn của bạn: ";
        cin >> choice;
        
        Bus* bus = nullptr; 
        
        switch (choice) {
            case 0:
                cout << "Cảm ơn đã sử dụng hệ thống!" << endl;
                return 0;
                
            case 1:
                cout << "Nhập mã tuyến: ";
                cin >> busId;
                cout << "Nhập thời gian khởi hành: ";
                cin >> departureTime;
                cout << "Nhập số ghế: ";
                cin >> seats;
                cout << "Nhập thời hạn xác nhận (giây): ";
                cin >> timeLimit;
                system.addBus(busId, departureTime, seats, timeLimit);
                break;
                
            case 2:
                cout << "Nhập mã tuyến: ";
                cin >> busId;
                
                bus = system.findBus(busId);
                if (bus == nullptr) {
                    cout << "Không tìm thấy tuyến xe!" << endl;
                    break;
                }
                
                cout << "Nhập tên: ";
                cin.ignore();
                getline(cin, name);
                
                cout << "Nhập số điện thoại: ";
                cin >> phone;
                
                bus->bookTicket(name, phone);
                break;
                
            case 3:
                cout << "Nhập mã tuyến: ";
                cin >> busId;
                
                bus = system.findBus(busId);
                if (bus == nullptr) {
                    cout << "Không tìm thấy tuyến xe!" << endl;
                    break;
                }
                
                cout << "Nhập số ghế cần hủy: ";
                cin >> seatNumber;
                
                bus->cancelTicket(seatNumber);
                break;
                
            case 4:
                cout << "Nhập mã tuyến: ";
                cin >> busId;
                
                bus = system.findBus(busId);
                if (bus == nullptr) {
                    cout << "Không tìm thấy tuyến xe!" << endl;
                    break;
                }
                
                cout << "Nhập tên người xác nhận: ";
                cin.ignore();
                getline(cin, name);
                
                bus->confirmTicket(name);
                break;
                
            case 5:
                cout << "Nhập mã tuyến: ";
                cin >> busId;
                
                bus = system.findBus(busId);
                if (bus == nullptr) {
                    cout << "Không tìm thấy tuyến xe!" << endl;
                    break;
                }
                
                bus->displayInfo();
                break;
                
            case 6:
                system.displayAllBuses();
                break;
                
            case 7:
                system.checkAllExpiredConfirmations();
                cout << "Đã kiểm tra tất cả thời hạn xác nhận" << endl;
                break;
                
            default:
                cout << "Lựa chọn không hợp lệ!" << endl;
        }
    }
    
    return 0;
}