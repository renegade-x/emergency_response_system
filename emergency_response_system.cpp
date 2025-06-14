#include <iostream>
#include <string>

using namespace std;

class Emergency {
public:
    int emergency_id;
    string emergency_type;
    int emergency_severity;
    string emergency_description;
    string emergency_location;
    time_t emergency_timestamp;

    Emergency(int id, string type, int severity, string desc, string loc) : 
        emergency_id(id), emergency_type(type), emergency_severity(severity), emergency_description(desc), emergency_location(loc) {
        emergency_timestamp = time(0);
    }
};

struct ListNode {
    Emergency* emergency_data;
    ListNode* next_node;
    ListNode* prev_node;

    ListNode(Emergency* emergency) : emergency_data(emergency), next_node(nullptr), prev_node(nullptr) {}
};

class EmergencyQueue {
private:
    ListNode* front_node;
    ListNode* rear_node;

public:
    EmergencyQueue() : front_node(nullptr), rear_node(nullptr) {}

    void enqueue(Emergency* emergency) {
        ListNode* new_node = new ListNode(emergency);
        if (rear_node == nullptr) {
            front_node = rear_node = new_node;
        } else {
            rear_node->next_node = new_node;
            rear_node = new_node;
        }
    }

    Emergency* dequeue() {
        if (is_empty()) return nullptr;
        ListNode* temp_node = front_node;
        Emergency* emergency = temp_node->emergency_data;
        front_node = front_node->next_node;
        if (front_node == nullptr) rear_node = nullptr;
        delete temp_node;
        return emergency;
    }

    bool is_empty() {
        return front_node == nullptr;
    }

    void display_queue() {
        for (ListNode* temp_node = front_node; temp_node != nullptr; temp_node = temp_node->next_node) {
            cout << "ID: " << temp_node->emergency_data->emergency_id << ", Type: " << temp_node->emergency_data->emergency_type 
                 << ", Severity: " << temp_node->emergency_data->emergency_severity << ", Location: " << temp_node->emergency_data->emergency_location << endl;
        }
    }
};

class EmergencyList {
private:
    ListNode* head_node;
    ListNode* tail_node;

public:
    EmergencyList() : head_node(nullptr), tail_node(nullptr) {}

    void insert_emergency(Emergency* emergency) {
        ListNode* new_node = new ListNode(emergency);
        if (tail_node == nullptr) {
            head_node = tail_node = new_node;
        } else {
            tail_node->next_node = new_node;
            new_node->prev_node = tail_node;
            tail_node = new_node;
        }
    }

    void remove_emergency(int id) {
        for (ListNode* current_node = head_node; current_node != nullptr; current_node = current_node->next_node) {
            if (current_node->emergency_data->emergency_id == id) {
                if (current_node->prev_node) current_node->prev_node->next_node = current_node->next_node;
                if (current_node->next_node) current_node->next_node->prev_node = current_node->prev_node;
                if (current_node == head_node) head_node = current_node->next_node;
                if (current_node == tail_node) tail_node = current_node->prev_node;
                delete current_node;
                return;
            }
        }
    }

    void display_list() {
        for (ListNode* temp_node = head_node; temp_node != nullptr; temp_node = temp_node->next_node) {
            cout << "ID: " << temp_node->emergency_data->emergency_id << ", Type: " << temp_node->emergency_data->emergency_type 
                 << ", Severity: " << temp_node->emergency_data->emergency_severity << ", Location: " << temp_node->emergency_data->emergency_location << endl;
        }
    }

    void sort_by_severity() {
        if (head_node == nullptr || head_node->next_node == nullptr) return;
        bool swapped;
        do {
            swapped = false;
            for (ListNode* current_node = head_node; current_node->next_node != nullptr; current_node = current_node->next_node) {
                if (current_node->emergency_data->emergency_severity < current_node->next_node->emergency_data->emergency_severity) {
                    swap(current_node->emergency_data, current_node->next_node->emergency_data);
                    swapped = true;
                }
            }
        } while (swapped);
    }
};

class EmergencyStack {
private:
    ListNode* top_node;

public:
    EmergencyStack() : top_node(nullptr) {}

    void push_emergency(Emergency* emergency) {
        ListNode* new_node = new ListNode(emergency);
        new_node->next_node = top_node;
        top_node = new_node;
    }

    Emergency* pop_emergency() {
        if (is_empty()) return nullptr;
        ListNode* temp_node = top_node;
        Emergency* emergency = temp_node->emergency_data;
        top_node = top_node->next_node;
        delete temp_node;
        return emergency;
    }

    bool is_empty() {
        return top_node == nullptr;
    }

    void display_stack() {
        for (ListNode* temp_node = top_node; temp_node != nullptr; temp_node = temp_node->next_node) {
            cout << "ID: " << temp_node->emergency_data->emergency_id << ", Type: " << temp_node->emergency_data->emergency_type 
                 << ", Severity: " << temp_node->emergency_data->emergency_severity << ", Location: " << temp_node->emergency_data->emergency_location << endl;
        }
    }

    ListNode* get_top_node() const { return top_node; }
};

class EmergencyResponseSystem {
private:
    EmergencyQueue emergency_queue;
    EmergencyList police_emergencies;
    EmergencyList fire_emergencies;
    EmergencyList medical_emergencies;
    EmergencyStack resolved_emergencies;
    int emergency_id_counter;

public:
    EmergencyResponseSystem() : emergency_id_counter(1) {}

    void register_emergency() {
        string emergency_type, emergency_description, emergency_location;
        int emergency_severity;

        cout << "Enter emergency type (Police/Fire/Medical): ";
        cin >> emergency_type;
        cout << "Enter severity (1-10): ";
        cin >> emergency_severity;
        cout << "Enter description: ";
        cin.ignore();
        getline(cin, emergency_description);
        cout << "Enter location: ";
        getline(cin, emergency_location);

        Emergency* new_emergency = new Emergency(emergency_id_counter++, emergency_type, emergency_severity, emergency_description, emergency_location);
        emergency_queue.enqueue(new_emergency);

        if (emergency_type == "Police") police_emergencies.insert_emergency(new_emergency);
        else if (emergency_type == "Fire") fire_emergencies.insert_emergency(new_emergency);
        else if (emergency_type == "Medical") medical_emergencies.insert_emergency(new_emergency);

        cout << "Emergency registered successfully." << endl;
    }

    void process_emergency() {
        if (emergency_queue.is_empty()) {
            cout << "No emergencies to process." << endl;
            return;
        }

        Emergency* emergency = emergency_queue.dequeue();
        cout << "Processing emergency: ID " << emergency->emergency_id << ", Type: " << emergency->emergency_type << ", Severity: " << emergency->emergency_severity << endl;
        resolved_emergencies.push_emergency(emergency);

        if (emergency->emergency_type == "Police") police_emergencies.remove_emergency(emergency->emergency_id);
        else if (emergency->emergency_type == "Fire") fire_emergencies.remove_emergency(emergency->emergency_id);
        else if (emergency->emergency_type == "Medical") medical_emergencies.remove_emergency(emergency->emergency_id);

        cout << "Emergency processed and resolved." << endl;
    }

    void view_emergencies_by_category() {
        int choice;
        cout << "Select category:\n1. Police\n2. Fire\n3. Medical\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Police Emergencies:" << endl;
                police_emergencies.display_list();
                break;
            case 2:
                cout << "Fire Emergencies:" << endl;
                fire_emergencies.display_list();
                break;
            case 3:
                cout << "Medical Emergencies:" << endl;
                medical_emergencies.display_list();
                break;
            default:
                cout << "Invalid choice." << endl;
        }
    }

    void view_resolved_emergencies() {
        cout << "Resolved Emergencies:" << endl;
        resolved_emergencies.display_stack();
    }

    void display_statistics() {
        int total_reported = emergency_id_counter - 1;
        int total_resolved = 0;
        for (ListNode* temp_node = resolved_emergencies.get_top_node(); temp_node != nullptr; temp_node = temp_node->next_node) {
            total_resolved++;
        }
        int total_pending = total_reported - total_resolved;

        cout << "Emergency Statistics:" << endl;
        cout << "Total Reported: " << total_reported << endl;
        cout << "Total Resolved: " << total_resolved << endl;
        cout << "Total Pending: " << total_pending << endl;
    }
};

int main() {
    EmergencyResponseSystem emergency_system;
    int user_choice;

    while (true) {
        cout << "\nEmergency Response System Menu:\n"
             << "1. Register New Emergency\n"
             << "2. Process Emergency\n"
             << "3. View Emergencies by Category\n"
             << "4. View Resolved Emergencies\n"
             << "5. Display Statistics\n"
             << "6. Exit\n"
             << "Enter your choice: ";
        
        cin >> user_choice;
        
        switch (user_choice) {
            case 1:
                emergency_system.register_emergency();
                break;
            case 2:
                emergency_system.process_emergency();
                break;
            case 3:
                emergency_system.view_emergencies_by_category();
                break;
            case 4:
                emergency_system.view_resolved_emergencies();
                break;
            case 5:
                emergency_system.display_statistics();
                break;
            case 6:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }
    
    return 0;
}
