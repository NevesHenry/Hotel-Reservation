# Hotel-Reservation
## OOP of a Hotel Reservation System

The Hotel has Rooms and accept Customers. In this program, I implemented a Hotel class, a Customer class and a Room class in C++.

 - The Hotel class has a number of rooms and a number of customers requesting rooms. Customers want rooms with different number of 
beds. My hotel, have 100 rooms with only one bed, 50 rooms with 2 beds 
and 30 rooms with 3 beds.

 - The Room class has information such as the customer who’s currently occupying it, when the customer gets the room (check in date), 
when the customer is leaving the room (check out date), and the number of beds in the room.

 - The Customer class carries the customer id and the number of requested beds. 
 
 > I decided to use the STL vector class to implement the Hotel with a list of Rooms. The vector behaviour much like an array. 
That means it is easy to access a specific element. Each element in my vector is a Room. In a hotel, those action are way more 
common than add a new Room. Adding and removing rooms means building new room in the hotel. Accessing the element is how I allocate
Customers in the available Rooms.

 > If adding and removing rooms become a common task in the application, I would implement a Linked List instead of using a vector. The 
good news is that I don’t have to modify the Room class. The Room class will become my node and I will have to only worry about the pointers 
linking the list.
