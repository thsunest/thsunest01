import heapq  
  
class Node:  
    def __init__(self, position, parent=None, g=0, h=0, f=0):  
        self.position = position  # (x, y)坐标  
        self.parent = parent      # 父节点  
        self.g = g               # 从起点到当前节点的移动代价  
        self.h = h               # 启发式函数，当前节点到目标节点的最短距离（不考虑地形代价）  
        self.f = f               # 估价函数值 f(n) = g(n) + h(n)  
  
    # 定义比较函数，用于优先队列  
    def __lt__(self, other):  
        return self.f < other.f  
  
def heuristic(a, b):  
    # 使用曼哈顿距离作为启发式函数  
    return abs(a[0] - b[0]) + abs(a[1] - b[1])  
  
def get_neighbors(position, grid):  
    # 获取当前节点的所有相邻节点  
    neighbors = []  
    for dx, dy in [(-1, 0), (1, 0), (0, -1), (0, 1), (-1, -1), (-1, 1), (1, -1), (1, 1)]:  
        x, y = position[0] + dx, position[1] + dy  
        if 0 <= x < len(grid) and 0 <= y < len(grid[0]) and grid[x][y] != 5:  
            neighbors.append((x, y))  
    return neighbors  
  
def a_star_search(grid, start, end):  
    open_list = []  
    closed_list = set()  
    start_node = Node(start, None, 0, heuristic(start, end), heuristic(start, end))  
    heapq.heappush(open_list, start_node)  
  
    terrain_costs = {0: 0, 2: 2, 4: 4}  # 地形代价  
  
    while open_list:  
        current_node = heapq.heappop(open_list)  
        closed_list.add(current_node.position)  
  
        if current_node.position == end:  
            # 找到目标节点，重建路径  
            path = []  
            while current_node:  
                path.append(current_node.position)  
                current_node = current_node.parent  
            return path[::-1]  # 返回反转后的路径  
  
        for neighbor in get_neighbors(current_node.position, grid):  
            if neighbor in closed_list:  
                continue  
  
            tentative_g_cost = current_node.g + (1 if (neighbor[0] - current_node.position[0]) ** 2 + (neighbor[1] - current_node.position[1]) ** 2 == 1 else 2)  
  
            if (tentative_g_cost < (open_list_node.g if (open_list_node := next((node for node in open_list if node.position == neighbor), None)) else float('inf'))):  
                terrain_cost = terrain_costs.get(grid[neighbor[0]][neighbor[1]], 0)  # 获取地形代价  
                tentative_f_cost = tentative_g_cost + terrain_cost + heuristic(neighbor, end) - terrain_cost  # f(n) = g(n) + h(n)，但g(n)要加上地形代价计算总代价，而f(n)用于排序时不考虑地形代价重复加  
  
                new_node = Node(neighbor, current_node, tentative_g_cost + terrain_cost if neighbor != start else 0, heuristic(neighbor, end), tentative_f_cost + terrain_cost - terrain_cost)  # 初始化新节点，g(n)考虑地形代价  
  
                if not any(neighbor_node.position == neighbor for neighbor_node in open_list):  
                    heapq.heappush(open_list, new_node)  
  
    return None  # 没有找到路径  
  
# 示例地图（0：普通地形，2：溪流，4：沙漠，5：不可通行，1：起点，3：终点）  
grid = [  
    [0, 0, 0, 0, 0, 0, 5, 3, 0, 0],  
    [0, 0, 2, 0, 4, 0, 0, 0, 0, 0],  
    [4, 4, 0, 0, 5, 0, 5, 2, 0, 0],  
    [0, 4, 0, 0, 0, 0, 5, 0, 0, 0],  
    [0, 4, 0, 0, 0, 0, 4, 0, 0, 0],  
    [0, 4, 0, 0, 2, 0, 0, 4, 0, 0],  
    [1, 0, 0, 2, 0, 0, 2, 0, 2, 0],  
    [0, 0, 2, 0, 0, 0, 0, 0, 0, 0],  
    [0, 2, 0, 0, 0, 0, 0, 0, 0, 0],  
]  
  
start = (6, 0)  
end = (0, 8)  
  
path = a_star_search(grid, start, end)  
print("最短路径:", path)