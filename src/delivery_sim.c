#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "delivery_sim.h"

char* get_delivery_status(delivery_status_e delivery_status) {
    switch (delivery_status) {
        case 0: return "NOT_DELIVERED";
        case 1: return "BEING_DELIVERED";
        case 2: return "DELIVERED";
        default: return NULL;
    }
}

void print_package(int selector, package_t package) {
    switch(selector) {
        case 0: printf("Package height: %.2lf meters\n", package.height);
            break;
        case 1: printf("Package width: %.2lf meters\n", package.width);
            break;
        case 2: printf("Package length: %.2lf meters\n", package.length);
            break;
        case 3: printf("Package weight: %.2lf kilo\n", package.weight);
            break;
        case 4: printf("Package priority: %d\n", package.priority);
            break;
        case 5: printf("Package node_id: %d\n", package.node_id);
            break;
        case 6: printf("Package truck_id: %d\n", package.truck_id);
            break;
        case 7: printf("Package delivery_status: %s\n", get_delivery_status(package.delivery_status));
            break;
        default:
            for (int i = 0; i < 8; i++) {
                print_package(i, package);
            }
    }
}


void print_node(int selector, node_t node) {
    switch(selector) {
        case 0: printf("Node area: %d\n", node.area);
            break;
        case 1: printf("Node location_x: %d\n", node.location_x);
            break;
        case 2: printf("Node location_y: %d\n", node.location_y);
            break;
        case 3: printf("Node id: %d\n", node.id);
            break;
        case 4:
            printf("Node packages: ");
            printf("----------\n");
            for (int i = 0; i < 30; i++) {
                print_package(-1, node.packages[i]);
            }
            printf("----------\n");
            break;
        default:
            for (int i = 0; i < 5; i++) {
                print_node(i, node);
            }
    }
}

void print_truck(int selector, truck_t truck) {
        switch (selector) {
            case 0: printf("Truck max_weight: %.2lf kilo\n", truck.max_weight);
                break;
            case 1: printf("Truck max_volume: %.2lf cubic meters\n", truck.max_volume);
                break;
            case 2: printf("Truck average_speed: %d kilometers an hour\n", truck.average_speed);
                break;
            case 3: printf("Truck id: %d\n", truck.id);
                break;
            default:
                for (int i = 0; i < 4; i++) {
                    print_truck(i, truck);
                }
        }
}

package_t generate_random_package() {
    int priority = rand() % 5 + 1;
    int node_id = rand() % 5 + 1;
    int truck_id = rand() % 5 + 1;

    double height = rand() % 2 + 1;
    double width = rand() % 2 + 1;
    double length = rand() % 2 + 1;
    double weight = rand() % 25 + 1;

    package_t package = create_package(priority, node_id, truck_id, height, width, length, weight);

    return package;
}