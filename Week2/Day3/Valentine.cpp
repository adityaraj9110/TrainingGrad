#include <bits/stdc++.h>
using namespace std;
class Country {
    int countryId;
    string name;

public:
    // Constructor
    Country(int id, const string& countryName) : countryId(id), name(countryName) {}

    // Getters
    int getCountryId() const { return countryId; }
    string getName() const { return name; }
};

class City {
    int cityId;
    string name;
    int countryId;
    vector<int> walls;

public:
    // Constructor
    City(int id, const string& cityName, int countryId) : cityId(id), name(cityName), countryId(countryId) {}

    // Getters
    int getCityId() const { return cityId; }
    string getName() const { return name; }
    int getCountryId() const { return countryId; }
    vector<int> getWalls() const { return walls; }

    // Method to add walls
    void addWall(int wallId) { walls.push_back(wallId); }
};

class Wall {
    int wallId;
    vector<int> bricks;

public:
    // Constructor
    Wall(int id) : wallId(id) {}

    // Getters
    int getWallId() const { return wallId; }
    vector<int> getBricks() const { return bricks; }

    // Method to add bricks
    void addBrick(int brickId) { bricks.push_back(brickId); }
};
// class for brick
class Brick {
    int brickId;
    string content;
    int ownerId;
    vector<string> comments;

public:
    // Constructor
    Brick(int id) : brickId(id) {}

    // Getters
    int getBrickId() const { return brickId; }
    string getContent() const { return content; }
    int getOwnerId() const { return ownerId; }
    vector<string> getComments() const { return comments; }

    // Setters
    void setContent(const string& newContent) { content = newContent; }
    void setOwnerId(int newOwnerId) { ownerId = newOwnerId; }

    // Method to add comments
    void addComment(const string& comment) { comments.push_back(comment); }
};

class User {
    int userId;
    string name;

public:
    // Constructor
    User(int id, const string& userName) : userId(id), name(userName) {}

    // Getters
    int getUserId() const { return userId; }
    string getName() const { return name; }
};
// owner class
class Owner : public User {
    vector<int> bricksOwned;

public:
    // Constructor
    Owner(int id, const string& userName) : User(id, userName) {}

    // Method to add owned bricks
    void addBrick(int brickId) { bricksOwned.push_back(brickId); }
};

class Admin : public User {
public:
    // Constructor
    Admin(int id, const string& userName) : User(id, userName) {}

    // Method to edit brick content
    void editBrickContent(Brick& brick, const string& newContent) {
        brick.setContent(newContent);
    }
};
// location class
class Location {
    int countryId;
    int cityId;
    int wallId;
    int brickId;

public:
    // Constructor
    Location(int country, int city, int wall, int brick)
        : countryId(country), cityId(city), wallId(wall), brickId(brick) {}

    // Getters
    int getCountryId() const { return countryId; }
    int getCityId() const { return cityId; }
    int getWallId() const { return wallId; }
    int getBrickId() const { return brickId; }
};

class Middleware {
    vector<Brick> bricks;

public:
    // Method to add or edit bricks
    void addOrEditBrick(const Location& loc, Owner& owner, const string& content) {
        // Check if brick already exists at the location
        for (auto& brick : bricks) {
            if (brick.getBrickId() == loc.getBrickId()) {
                // Brick exists, so edit its content
                brick.setContent(content);
                return;
            }
        }
        // Brick doesn't exist, so create a new one
        Brick newBrick(bricks.size() + 1); // Assign a new ID
        newBrick.setContent(content);
        newBrick.setOwnerId(owner.getUserId());
        bricks.push_back(newBrick);
        owner.addBrick(newBrick.getBrickId()); // Add the brick to the owner's list
    }

    // Method to handle write operations
    void handleWriteOperation(const Location& loc, Owner& owner, const string& content) {
        // Check if brick already exists at the location
        for (auto& brick : bricks) {
            if (brick.getBrickId() == loc.getBrickId()) {
                // Brick exists, so check if it has content
                if (!brick.getContent().empty()) {
                    cout << "Brick has already content" << endl;
                    return;
                }
                // Brick exists and is empty, so edit its content
                brick.setContent(content);
                return;
            }
        }
        // Brick doesn't exist, so create a new one
        Brick newBrick(bricks.size() + 1); // Assign a new ID
        newBrick.setContent(content);
        newBrick.setOwnerId(owner.getUserId());
        bricks.push_back(newBrick);
        owner.addBrick(newBrick.getBrickId()); // Add the brick to the owner's list
    }
    // this is for the handling read operation
    string readBrickContent(const Location& loc) {
        for (const auto& brick : bricks) {
            if (brick.getBrickId() == loc.getBrickId()) {
                return brick.getContent();
            }
        }
        return ""; // Brick not found
    }
     // Method to delete a brick
    void deleteBrick(const Location& loc) {
        // Iterate through bricks
        auto Brick = bricks.begin();
        while (Brick != bricks.end()) {
            // Check if the brick ID matches the specified location's brick ID
            if (Brick->getBrickId() == loc.getBrickId()) {
                // If a match is found, erase the brick
                Brick = bricks.erase(Brick);
            } else {
                // Move to the next brick
                ++Brick;
            }
        }
    }
};
int main(){

}