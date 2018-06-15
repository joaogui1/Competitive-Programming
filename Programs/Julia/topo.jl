depend = Set{String}()
courses = Set{String}()
for l in readlines(open("depend.in"))
  push!(depend, chomp(l))
end
for l in readlines(open("courses.in"))
  push!(courses, chomp(l))
end
while true
  print("O que você deseja fazer?\n1. Imprimir as cadeiras livres\n2. Apagar um requisito\n3. Sair\n")
  aus = chomp(readline())
  n = parse(Int, aus)
  if n == 1
    tmp = copy(courses)
    for l in depend
      v = split(l, '_')
      v[1] = chomp(v[1])
      if v[1] in courses
        delete!(courses, v[1])
      end
    end
    for i in courses
      println(i)
    end
    courses = copy(tmp)
  elseif n == 2
    println("Diga o nome do curso")
    curso = chomp(readline())
    delete!(courses, curso)
    for l in depend
      v = split(l, '_')
      if v[2] == curso
        delete!(depend, l)
      end
    end
  else
    break
  end
end
