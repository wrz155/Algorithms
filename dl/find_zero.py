def find_zero(f, left, right, tolerance):
    """
    通过二分法寻找函数 f(x) 在区间 [left, right] 中的零点，精度要求为 tolerance
    """
    if f(left) * f(right) > 0:
        raise ValueError("函数在指定区间内没有零点")

    while abs(right - left) > tolerance:
        mid = (left + right) / 2
        if f(mid) == 0:
            return mid
        elif f(mid) * f(left) < 0:
            right = mid
        else:
            left = mid
    return (left + right) / 2


def newton_method(f, df, a, tolerance):
    x = a
    while f(x) > tolerance:
        x = x - f(x) / df(x)

    return x



# 定义你的函数 f(x)
def f(x):
    return x**2


def df(x):
    return 2*x


# 定义区间和精度
left = -1
right = 1
tolerance = 1e-4

# 寻找零点
zero = newton_method(f, df, -1.0, tolerance)
print("零点:", zero)
