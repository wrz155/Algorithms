import math

class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y


class Node:
    def __init__(self, point):
        self.point = point
        self.next = None


def angle_between(p1, p2, p3):
    # 计算夹脚
    rad = math.atan2(p3.y - p2.y, p3.x - p2.x) - math.atan2(p1.y - p2.y, p1.x - p2.x)
    angle = math.degrees(rad)
    if angle < 0:
        angle += 360
    return angle



def concavity_convexity(head):
    if not head:
        return None

    current = head
    while current.next != head:
        prev = current
        current = current.next
        next = current.next if current.next else head

        angle = angle_between(prev.point, current.point, next.point)
        if angle > 180:
            return "concave"  # 凹多边形
        elif angle < 180:
            return "convex"  # 凸多边形

    # 处理环形链表的最后一个节点
    angle = angle_between(current.point, prev.point, head.point)
    if angle > 180:
        return "concave"  # 凹多边形
    elif angle < 180:
        return "convex"  # 凸多边形

    return "unknown"


    pass


def main():
    p1 = Point(0, 0)
    p2 = Point(1, 1)
    p3 = Point(2, 0)

    node1 = Node(p1)
    node2 = Node(p2)
    node3 = Node(p3)
    node1.next = node2
    node2.next = node3
    node3.next = node1

    # 判断凸凹性
    result = concavity_convexity(node1)
    print("The polygon is", result)




if __name__ == '__main__':
    main()

