-- Write your query below
select
    person.first_name,
    person.last_name,
    address.city,
    address.state
from person
left join address
    on person.person_id = address.person_id;

