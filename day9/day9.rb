
file = File.read("day9-input.txt").split(/\n/)

visited = []

currentTail = [0, 0]
currentHead = [0, 0]

visited.push(currentTail)

file.each do | row |
    row = row.split(/ /, 2)
    case row[0]
    when "U"
        moving = 1
        moveIndex = 0
        nonMoveIndex = 1
    when "D"
        moving = -1
        moveIndex = 0
        nonMoveIndex = 1
    when "R"
        moving = 1
        moveIndex = 1
        nonMoveIndex = 0
    when "L"
        moving = -1
        moveIndex = 1
        nonMoveIndex = 0
    end
    for i in 1..row[1].to_i do
        currentHead[moveIndex]+=moving
        if currentHead[moveIndex] > currentTail[moveIndex] + 1
            currentTail[moveIndex] += moving
            if currentHead[nonMoveIndex] > currentTail[nonMoveIndex]
                currentTail[nonMoveIndex] += 1
            elsif currentHead[nonMoveIndex] < currentTail[nonMoveIndex]
                currentTail[nonMoveIndex] -= 1
            end
        elsif currentHead[moveIndex] < currentTail[moveIndex] - 1
            currentTail[moveIndex] += moving
            if currentHead[nonMoveIndex] > currentTail[nonMoveIndex]
                currentTail[nonMoveIndex] += 1
            elsif currentHead[nonMoveIndex] < currentTail[nonMoveIndex]
                currentTail[nonMoveIndex] -= 1
            end
        end
        visited.push([currentTail[0], currentTail[1]])
    end
end

p(visited)

uniqueVisited = visited.uniq()
p(uniqueVisited.length())