## Questão
## É possível formar uma palavra a partir dos elementos de um conjunto?
## Retornar valor booleano

def can_construct(target,workbank,memo=[], idx=0):

    pos = target.find(workbank[idx])
    if pos != -1:
        memo.append(True)
        idx += 1
        try:
            suffix = target[len(workbank[idx]):]
            can_construct(suffix,workbank,memo, idx)
        except IndexError:
            pass
    else:
        memo.append(False)
        
    return all(memo)

print(can_construct('aaaac',['aa','bb','c']))
print(can_construct('skateboard',['ska','ate','bo', 'oard']))