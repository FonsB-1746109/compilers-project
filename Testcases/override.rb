def blub(a, b, c)
    if (a == b)
        return c
    elsif (a == c)
        return b
    else 
        return a
    end
end

def ret()
    return 1
    print(99999)
    return 2
    return 3
end

def a(a)


    print(a)


end
a    =    5
a(a)
a = true
a(a)

if (a)




			print(a)





end

b=0
until(!a)
    b += 1
    if (b==100)
        then a = false
    elsif (b==50)


        print(9999999)
    end
end

print(b) # print 100

c=0
while (c<=5)

    case c 
        when 0
            print(c*1) # print 0
        when 1
            print(c*10) # print 10
        when 2
            print(c*100) # print 200
        when 3
            print(c*1000) # print 3000
        when 4
            print(blub(4,123456789,c)) # print 123456789
        when 5
            print(blub(100,888,b)) # print 888
        else
            print(55555) # gebeurt nooit
    end

    c+=1
end


print(ret())

aap = true
a = 1 + aap

ret()