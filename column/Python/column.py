class Row:
    item = None
    down = None
    up = None

    def __init__(self, item = 0, down = None, up = None):
        self.item = item
        self.down = down
        self.up = up


class Column:
    label = ""
    next = None
    prev = None
    row: Row = None

    def __init__(self, label: str = "Column", next = None, prev = None, row: Row = None):
        self.label = label
        self.next = next
        self.prev = prev
        self.row = row

def add_column(column: Column, label: str):

    new_column = Column(label = label)

    if column.next is None:
        column.next = new_column
        new_column.prev = column

    elif curent_column.next is not None:
        
        while curent_column.next is not None:
            curent_column = curent_column.next
        
        curent_column.next = new_column
        new_column.prev = curent_column
    

def add_data_to_column(column: Column, item):
    
    new_row = Row(item=item)

    if column.row is None:
        column.row = new_row

    else:
        row = column.row
        while row.down is not None:
            row = column.row.down

        row.down = new_row
        new_row.up = row


def print_all_column(column: Column):

    c = column
    r :Row

    while c is not None:
        print(f"{c.label} :")
        r = column.row

        while r is not None:
            print(f"{r.item}")
            r = r.down

        c = c.next
            

def help():
    print("Enter number 1 to add a new item")
    print("Enter number 3 to print All Columns")
    print("Enter number 4 to Exit")

if __name__ == "__main__":

    c = Column("A")
    add_column(c, "B")

    is_run = True

    while is_run:
        help()

        select = int(input())

        if select == 1:
            item = int(input("Enter Your Number: "))
            add_data_to_column(c, item)

        if select == 3:
            print_all_column(c)
        
        if select == 4:
            is_run = False
        
        if select > 4 or select < 1:
            print(f"Number {select} is Not In list! please select correct number\n\n")
            continue

