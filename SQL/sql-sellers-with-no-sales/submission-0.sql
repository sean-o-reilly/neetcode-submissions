-- Write your query below

select seller.seller_name
from seller
where seller_id not in (
    select seller_id
    from orders
    where extract(year from sale_date) = 2020
)
order by seller.seller_name;