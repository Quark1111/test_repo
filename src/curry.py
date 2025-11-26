def sum3(a, b, c):
    return a + b + c

def curry(func, arity):
    if not isinstance(arity, int):
        raise TypeError("арность должна быть числом")
    if arity < 0:
        raise ValueError("арность не может быть отрицательной")
    if arity == 0:
        return lambda: func() 

    def curried(*args):
        if len(args) >= arity:
            return func(*args[:arity])
        else:
            return lambda *next_args: curried(*(args + next_args))

    return curried

def uncurry(curried_func, arity):
    if not isinstance(arity, int):
        raise TypeError("арность должна быть числом")
    if arity < 0:
        raise ValueError("арность не может быть отрицательной")
    
    def uncurried(*args):
        if len(args) != arity:
            raise ValueError("неверное количество аргументов")

        result = curried_func
        for arg in args:
            result = result(arg)

        return result

    return uncurried

sum3_curry = curry(sum3, 3)
sum3_uncurry = uncurry(sum3_curry, 3)
print(sum3_curry(1)(2)(3))
print(sum3_uncurry(1, 2, 3))
