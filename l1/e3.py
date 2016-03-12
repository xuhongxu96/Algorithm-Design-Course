import random

class Ship:
    n = 0
    def __init__(self):
        self.stop_time = 4 + random.randrange(41)
        Ship.n += 1
        self.name = "ship" + str(Ship.n)

class Dock:
    def __init__(self):
        self.ship = None
        self.waiting_ships = []
    def simulate(self, months = 60):
        Ship.n = 0
        self.ship = None
        self.waiting_ships = []
        hours = 0
        waiting_hours = 0
        while hours < months * 30 * 24:
            print("now is", hours, "hours")
            interval = 15 + random.randrange(31)
            print(interval, "hours later")
            hours += interval
            while self.ship != None and interval >= self.ship.stop_time:
                print(self.ship.name, "has left")
                waiting_hours += len(self.waiting_ships) * self.ship.stop_time
                if len(self.waiting_ships):
                    print(len(self.waiting_ships), "ships wait for", self.ship.stop_time, "hours")
                    print("so total waiting hours is", waiting_hours)
                interval -= self.ship.stop_time
                self.ship = None if len(self.waiting_ships) == 0 else self.waiting_ships.pop()
                if self.ship:
                    print(self.ship.name, "stopped")
            if self.ship:
                print(self.ship.name, "has been stopping for", interval, "hours")
                self.ship.stop_time -= interval
                print("so it still has to stop for", self.ship.stop_time, "hours")
            ship = Ship()
            print("A ship comes and it will stop for", ship.stop_time, "hours")
            print("It is called", ship.name)
            if self.ship == None:
                self.ship = ship
                print("Because no ship is here, it will comes in")
            else:
                self.waiting_ships.append(ship)
                print("Because there is one ship stopping, it has to wait")
                for s in self.waiting_ships:
                    print(" - ", s.name, "is waiting. It will stop for", s.stop_time, "hours")
            print(" + ", self.ship.name, 'is stopping and its remaining hour is', self.ship.stop_time)
            print("---")

        print(" - DEALING WITH REMAINING SHIPS - ")
        while self.ship != None:
            print(self.ship.name, "has left")
            waiting_hours += len(self.waiting_ships) * self.ship.stop_time
            if len(self.waiting_ships):
                print(len(self.waiting_ships), "ships wait for", self.ship.stop_time, "hours")
                print("so total waiting hours is", waiting_hours)
            self.ship = None if len(self.waiting_ships) == 0 else self.waiting_ships.pop()
            if self.ship:
                print(self.ship.name, "stopped")
        print("===========")
        print(Ship.n - 1, "ships used to come here")
        print(hours, "hours past")
        print(waiting_hours, "hours has been wasted")
        print(waiting_hours / 10, "万元 has to be paid")
        return waiting_hours / 10

if __name__ == "__main__":
    dock = Dock()
    waste = 0
    try_times = 10
    for times in range(0, try_times):
        print(times, "time started")
        waste += dock.simulate()
    print("\n",try_times, "次模拟后，发现等待消耗成本约为", waste / try_times, "万元")
    if waste >= 1350 * try_times:
        print(" > 大于1350万元，故扩建")
    else:
        print(" > 小于1350万元，故不扩建")
