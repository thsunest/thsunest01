def judge_repeat(value, lst=None):
    if lst is None:
        lst = []
    for item in lst:
        if item == value:
            return 1
    return 0

# 自定义函数，对已经整理好的综合数据库real_list进行最终的结果判断
def judge_last(lst):
    if '23' in lst:  # 食肉类
        if '12' in lst:  # 黄褐色
            if '21' in lst:  # 哺乳类
                if '13' in lst:  # 有斑点
                    print("黄褐色，有斑点,哺乳类，食肉类->金钱豹")
                    return "金钱豹"
            if '14' in lst:  # 有黑色条纹
                print("黄褐色，有黑色条纹，哺乳类，食肉类->虎")
                return "虎"
    if '14' in lst:  # 有黑色条纹
        if '24' in lst:  # 蹄类
            print("有黑色条纹，蹄类->斑马")
            return "斑马"
    if '24' in lst:  # 蹄类
        if '13' in lst:  # 有斑点
            if '15' in lst:  # 长脖
                if '16' in lst:  # 长腿
                    print("有斑点，有黑色条纹，长脖，蹄类->长颈鹿")
                    return "长颈鹿"
    if '20' in lst:  # 善飞
        if '22' in lst:  # 鸟类
            print("善飞，鸟类->信天翁")
            return "信天翁"
    if '22' in lst:  # 鸟类
        if '4' in lst:  # 不会飞
            if '15' in lst:  # 长脖
                if '16' in lst:  # 长腿
                    print("不会飞，长脖，长腿，鸟类->鸵鸟")
                    return "鸵鸟"
    if '4' in lst:  # 不会飞
        if '22' in lst:  # 鸟类
            if '18' in lst:  # 会游泳
                if '19' in lst:  # 黑白二色
                    print("不会飞，会游泳，黑白二色，鸟类->企鹅")
                    return "企鹅"

    print("\n根据所给条件无法判断为何种动物")
    return None

dict_before = {
    '1': '有毛发', 
    '2': '产奶', 
    '3': '有羽毛', 
    '4': '不会飞', 
    '5': '会下蛋', 
    '6': '吃肉', 
    '7': '有犬齿',
    '8': '有爪', 
    '9': '眼盯前方', 
    '10': '有蹄', 
    '11': '反刍', 
    '12': '黄褐色', 
    '13': '有斑点',
    '14': '有黑色条纹',
    '15': '长脖', 
    '16': '长腿', 
    '17': '不会飞', 
    '18': '会游泳', 
    '19': '黑白二色', 
    '20': '善飞',
    '21': '哺乳类',
    '22': '鸟类', 
    '23': '食肉类', 
    '24': '蹄类', 
    '25': '金钱豹', 
    '26': '虎', 
    '27': '长颈鹿', 
    '28': '斑马',
    '29': '鸵鸟', 
    '30': '企鹅', 
    '31': '信天翁'
}

print('''输入对应条件前面的数字:
*1:有毛发 2:产奶 3:有羽毛 4:不会飞 5:会下蛋 *
*6:吃肉 7:有犬齿 8:有爪 9:眼盯前方 10:有蹄 *
*11:反刍 12:黄褐色 13:有斑点 14:有黑色条纹 15:长脖 *
*16:长腿 17:不会飞 18:会游泳 19:黑白二色 20:善飞 *
*21：哺乳类 22:鸟类 23:食肉类 24：蹄类 *
当输入数字0时程序结束
''')

# 综合数据库
list_real = []

while True:
    num_real = input("请输入：")
    if num_real == '0':
        break
    if num_real in dict_before:  # 确保输入的数字在字典中
        list_real.append(num_real)
    else:
        print("无效输入，请输入有效的数字。")
        continue

print("\n前提条件为：")
# 输出前提条件
for i in list_real:
    print(dict_before[i], end=" ")
print("\n")

# 推理过程如下：
print("推理过程如下：")
result = judge_last(list_real)

if result is not None:
    print(f"所识别的动物为: {result}")