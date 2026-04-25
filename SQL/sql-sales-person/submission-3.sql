select name
from sales_person
where sales_id not in ( --- all sales_ids tied to CRIMSON
    select sales_person.sales_id
    from sales_person
    left join orders
        on orders.sales_id = sales_person.sales_id
    inner join company
        on company.com_id = orders.com_id
    where company.name = 'CRIMSON'
)
