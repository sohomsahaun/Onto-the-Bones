class Room {
	std::function<void(void)> fcreate, fstep, fdraw;
	char* name;

	public:

		Room() {}
		Room(char* name, std::function<void(void)> fcreate, std::function<void(void)> fstep, std::function<void(void)> fdraw) : fcreate(fcreate), fstep(fstep), fdraw(fdraw) {}
		Room(std::function<void(void)> fcreate, std::function<void(void)> fstep, std::function<void(void)> fdraw) : fcreate(fcreate), fstep(fstep), fdraw(fdraw) {}
		
		char* get_name() {
			return this->name;
		}

		void set_name(char* name) {
			this->name = name;
		}

		void create() {
			fcreate();
		}

		void step() {
			fstep();
		}

		void draw() {
			fdraw();
		}
};

Room *room;
Room *rMenu, *rGame;

// Functions
void room_goto(Room* targRoom, bool exec = true) {
	room = targRoom;
	if (exec) room->create();
}

/*
	rName = new Room("Name",
		// Create
		function<void(void)>([](void) {
			
		}),
		// Step
		function<void(void)>([](void) {
			
		}),
		// Draw
		function<void(void)>([](void) {
			
		})
	);
*/

