
def move_next(previous, follower, moving, moveIndex, nonMoveIndex)
    if previous[moveIndex] > follower[moveIndex] + 1
        follower[moveIndex] += moving
        if previous[nonMoveIndex] > follower[nonMoveIndex]
            follower[nonMoveIndex] += 1
        elsif previous[nonMoveIndex] < follower[nonMoveIndex]
            follower[nonMoveIndex] -= 1
        end
    elsif previous[moveIndex] < follower[moveIndex] - 1
        follower[moveIndex] += moving
        if previous[nonMoveIndex] > follower[nonMoveIndex]
            follower[nonMoveIndex] += 1
        elsif previous[nonMoveIndex] < follower[nonMoveIndex]
            follower[nonMoveIndex] -= 1
        end
    end
end

def solve()
    file = File.read("day9-input.txt").split(/\n/)

    visited_1 = []
    visited_2 = []

    currentTail_1 = Array.new(2) { |i| [0, 0]}
    currentTail_2 = Array.new(10) { |i| [0, 0]}

    visited_1.push([0, 0])
    visited_2.push([0, 0])

    file.each do | row |
        row = row.split(/ /, 2)
        case row[0]
        when "U"
            moving = -1
            moveIndex = 0
            nonMoveIndex = 1
        when "D"
            moving = 1
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
            currentTail_1[0][moveIndex]+=moving
            currentTail_2[0][moveIndex]+=moving
            move_next(currentTail_1[0], currentTail_1[1], moving, moveIndex, nonMoveIndex)
            visited_1.push([currentTail_1[1][0], currentTail_1[1][1]])
            for j in 1..9 do
                if currentTail_2[j][1] + 1 < currentTail_2[j-1][1]
                    moving_2 = 1
                    moveIndex_2 = 1
                    nonMoveIndex_2 = 0
                elsif currentTail_2[j][0] > 1 + currentTail_2[j-1][0]
                    moving_2 = -1
                    moveIndex_2 = 0
                    nonMoveIndex_2 = 1
                elsif currentTail_2[j][0] + 1 < currentTail_2[j-1][0]
                    moving_2 = 1
                    moveIndex_2 = 0
                    nonMoveIndex_2 = 1
                elsif currentTail_2[j][1] > 1 + currentTail_2[j-1][1]
                    moving_2 = -1
                    moveIndex_2 = 1
                    nonMoveIndex_2 = 0
                else
                    next
                end
                move_next(currentTail_2[j-1], currentTail_2[j], moving_2, moveIndex_2, nonMoveIndex_2)
            end
            visited_2.push([currentTail_2[9][0], currentTail_2[9][1]])
        end
    end
    p(currentTail_1)
    puts("Answer 1:", visited_1.uniq().length())
    p(currentTail_2)
    puts("Answer 2:", visited_2.uniq().length())
end

solve()