def bubble_Sort(list):
    for i in range(len(list)-1,-1,-1):
        move_elems_to_right(list,i)

def move_elems_to_right(list,end):
    for i in range(end):
        if list[i] > list[i + 1]:
            list[i],list[i + 1] = list[i + 1],list[i]

if __name__ == "__main__":
    list = [4,3,2,1]
    bubble_Sort(list)
    print(list)
