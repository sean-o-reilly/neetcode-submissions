-- Write your query below
select users.name, sum(coalesce(rides.distance, 0)) as travelled_distance
from users
full join rides 
    on users.id = rides.user_id
where users.name is not NULL
group by(users.name)
order by travelled_distance desc
