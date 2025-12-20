import struct

def heapify(mas, n, i):
    largest = i
    left = i * 2 + 1
    right = i * 2 + 2

    if left < n and mas[largest] < mas[left]:
        largest = left
    if right < n and mas[largest] < mas[right]:
        largest = right

    if largest != i:
        mas[i], mas[largest] = mas[largest], mas[i]
        heapify(mas, n, largest)


def HeapSort(mas):  
    n = len(mas)

    for i in range(n // 2 - 1, -1, -1):
        heapify(mas, n, i)

    for i in range(n - 1, -1, -1):
        mas[0], mas[i] = mas[i], mas[0]
        heapify(mas, i, 0)

    return mas


def encode(msg: str) -> tuple[str, dict[str, str]]:
    Occurrences = []
    Symbol = []
    CharacterEncode = {}
    CharacterEncode2 = {}
    
    for i in msg:
        flag = 1
        CharacterEncode[i] = ''
        for j in range(1, len(Symbol)):
            if i == Symbol[j]:
                flag = 0
                Occurrences[j] += 1
                break
        if flag:
            Occurrences.append(1)
            Symbol.append(i)
    
    Symbol = Symbol[1:]
    
    if len(Symbol) == 0:
        print('Файл пуст')
        return '', {}
    
    if len(Symbol) == 1:
        CharacterEncode[Symbol[0]] = '0'
        Result = '0' * len(msg)
        CharacterEncode2['0'] = Symbol[0]
        return Result, CharacterEncode2
    
    pairs = []
    for i in range(len(Symbol)):
        pairs.append([Occurrences[i], Symbol[i]])
    
    HeapSort(pairs)
    
    Occurrences = [pair[0] for pair in pairs]
    Symbol = [pair[1] for pair in pairs]
    
    ln = len(Symbol)
    
    while ln > 1:
        Occurrences1 = Occurrences.pop()
        Occurrences2 = Occurrences.pop()
        Symbol1 = Symbol.pop()
        Symbol2 = Symbol.pop()
        
        for char in Symbol1:
            CharacterEncode[char] = '0' + CharacterEncode[char]
        for char in Symbol2:
            CharacterEncode[char] = '1' + CharacterEncode[char]
        
        Symbol.append(Symbol1 + Symbol2)
        Occurrences.append(Occurrences1 + Occurrences2)
        ln -= 1
        
        pairs = []
        for i in range(len(Symbol)):
            pairs.append([Occurrences[i], Symbol[i]])
        HeapSort(pairs)
        Occurrences = [pair[0] for pair in pairs]
        Symbol = [pair[1] for pair in pairs]
    
    Result = ''
    for char in msg:
        Result += CharacterEncode[char]
        CharacterEncode2[CharacterEncode[char]] = char
    
    return Result, CharacterEncode2


def decode(encoded: str, table: dict[str, str]) -> str:
    Result = ''
    Encode = ''
    for i in encoded:
        Encode += i
        if Encode in table:
            Result += table[Encode]
            Encode = ''
    return Result


def encode_to_file(msg, filename):
    encoded, table = encode(msg)
    
    with open(filename, 'wb') as file:
        file.write(struct.pack('i', len(table)))
        
        for code, char in table.items():
            file.write(struct.pack('i', ord(char)))
            code_length = len(code)
            file.write(struct.pack('i', code_length))
            code_int = int(code, 2)
            code_bytes_len = (code_length + 7) // 8
            code_bytes = code_int.to_bytes(code_bytes_len, 'big')
            file.write(code_bytes)
        
        encoded_length = len(encoded)
        file.write(struct.pack('i', encoded_length))
        encoded_int = int(encoded, 2)
        encoded_bytes_len = (encoded_length + 7) // 8
        encoded_bytes = encoded_int.to_bytes(encoded_bytes_len, 'big')
        file.write(encoded_bytes)
    
    return table


def decode_from_file(filename):
    with open(filename, 'rb') as file:
        table = {}
        table_size = struct.unpack('i', file.read(4))[0]

        for i in range(table_size):
            char_code = struct.unpack('i', file.read(4))[0]
            char = chr(char_code)
            code_length = struct.unpack('i', file.read(4))[0]
            code_bytes_len = (code_length + 7) // 8
            code_bytes = file.read(code_bytes_len)
            code_int = int.from_bytes(code_bytes, 'big')
            code = bin(code_int)[2:].zfill(code_length)
            table[code] = char

        encoded_length = struct.unpack('i', file.read(4))[0]
        encoded_bytes_len = (encoded_length + 7) // 8
        encoded_bytes = file.read(encoded_bytes_len)
        encoded_int = int.from_bytes(encoded_bytes, 'big')
        encoded = bin(encoded_int)[2:].zfill(encoded_length)

        return decode(encoded, table)


def main():
    while True:
        print("Введите операцию, которую хотите сделать:")
        print("0 - выйти из меню")
        print("1 - кодирование файла")
        print("2 - раскодировать файл")
        
        try:
            operation = int(input("Ваш выбор: "))
        except ValueError:
            print("Ошибка! Введите число от 0 до 2")
            continue

        if operation == 0:
            break
        
        elif operation == 1:
            input_file = input("Введите путь к файлу или сообщение: ")
            output_file = input("Введите путь для сохранения закодированного файла: ")
            
            try:
                with open(input_file, 'r', encoding='utf-8') as file:
                    text = file.read()
                print(f"Прочитано из файла: {len(text)} символов")
                encode_to_file(text, output_file)
                print(f"Успешно закодировано и сохранено в {output_file}!")
            except FileNotFoundError:
                print(f"Кодируем как текст: {len(input_file)} символов")
                encode_to_file(input_file, output_file)
                print(f"Успешно закодировано и сохранено в {output_file}!")
            except Exception as e:
                print(f"Ошибка при кодировании: {e}")
        
        elif operation == 2:
            file_input = input("Введите путь к файлу для декодирования: ")
            try:
                decoded_text = decode_from_file(file_input)
                print(f"Раскодированный текст:\n{decoded_text}")
                
                save = input("Сохранить результат в файл? (да/нет): ").lower()
                if save == 'да':
                    save_file = input("Введите имя файла для сохранения: ")
                    with open(save_file, 'w', encoding='utf-8') as f:
                        f.write(decoded_text)
                    print(f"Результат сохранен в {save_file}")
                
                clear = input("Очистить исходный файл? (да/нет): ").lower()
                if clear == 'да':
                    with open(file_input, "wb") as f:
                        f.truncate(0)
                    print("Исходный файл очищен!")
                    
            except FileNotFoundError:
                print("Файл не существует!")
            except Exception as e:
                print(f"Ошибка при декодировании: {e}")
                print("Убедитесь, что файл был создан этой программой")
        
        else:
            print("Неверная операция! Введите 0, 1 или 2")


if __name__ == "__main__":
    main()
