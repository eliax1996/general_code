package view;

import android.support.v7.widget.RecyclerView;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ProgressBar;
import android.widget.TextView;

import java.util.List;

import data.ListItem;
import it.riequilibrium.eliax1996.apppalestra.R;
import logic.Controller;

/**
 * Created by eliamigliore on 04/04/18.
 */

public class CustomAdapter extends RecyclerView.Adapter<CustomAdapter.CustomViewHolder> {//6

    private LayoutInflater layoutInflater;
    private List<ListItem> listOfData;
    private Controller controller;

    public CustomAdapter(LayoutInflater layoutInflater,List<ListItem> listOfData,Controller controller){
        this.layoutInflater = layoutInflater;
        this.listOfData = listOfData;
        this.controller = controller;
    }

    /**
     * 13.
     * Inflates a new View (in this case, R.layout.item_data), and then creates/returns a new
     * CustomViewHolder object.
     *
     * @param parent   Unfortunately the docs currently don't explain this at all :(
     * @param viewType Unfortunately the docs currently don't explain this at all :(
     * @return
     */
    public CustomAdapter.CustomViewHolder onCreateViewHolder(ViewGroup parent, int viewType) {
        View v = layoutInflater.inflate(R.layout.item_data, parent, false);
        return new CustomAdapter.CustomViewHolder(v);
    }

    /**
     * This method "Binds" or assigns Data (from listOfData) to each View (ViewHolder).
     *
     * @param holder   The current ViewHolder instance for a given position
     * @param position The current position of the ViewHolder we are Binding to, based upon
     *                 our (listOfData). So for the second ViewHolder we create, we'll bind data
     *                 from the second Item in listOfData.
     */
    @Override
    public void onBindViewHolder(CustomAdapter.CustomViewHolder holder, int position) {
        //11. and now the ViewHolder data
        ListItem currentItem = listOfData.get(position);

        holder.message.setText(
                currentItem.getMessage()
        );

        holder.dateAndTime.setText(
                currentItem.getDateAndTime()
        );

        holder.loading.setVisibility(View.INVISIBLE);
    }

    /**
     * This method let's our Adapter determine how many ViewHolders it needs to create, based on
     * the size of the Dataset (List) which it is working with.
     *
     * @return the size of the dataset, generally via List.size()
     */
    @Override
    public int getItemCount() {
        // 12. Returning 0 here will tell our Adapter not to make any Items. Let's fix that.
        return listOfData.size();
    }

    /**
     * 5.
     * Each ViewHolder contains Bindings to the Views we wish to populate with Data.
     */
    class CustomViewHolder extends RecyclerView.ViewHolder implements View.OnClickListener {

        //10. now that we've made our layouts, let's bind them
        private TextView dateAndTime;
        private TextView message;
        private ViewGroup container;
        private ProgressBar loading;

        public CustomViewHolder(View itemView) {
            super(itemView);
            this.dateAndTime = (TextView) itemView.findViewById(R.id.lbl_date_and_time);
            this.message = (TextView) itemView.findViewById(R.id.lbl_message);
            this.loading = (ProgressBar) itemView.findViewById(R.id.pro_item_data);

            this.container = (ViewGroup) itemView.findViewById(R.id.root_list_item);
                /*
                We can pass "this" as an Argument, because "this", which refers to the Current
                Instance of type CustomViewHolder currently conforms to (implements) the
                View.OnClickListener interface. I have a Video on my channel which goes into
                Interfaces with Detailed Examples.

                Search "Android WTF: Java Interfaces by Example"
                 */
            this.container.setOnClickListener(this);
        }

        /**
         * 6.
         * Since I'm ok with the whole Container being the Listener, View v isn't super useful
         * in this Use Case. However, if I had a Single RecyclerView Item with multiple
         * Clickable Views, I could use v.getId() to tell which specific View was clicked.
         * See the comment within the method.
         *
         * @param v
         */
        @Override
        public void onClick(View v) {
            //getAdapterPosition() get's an Integer based on which the position of the current
            //ViewHolder (this) in the Adapter. This is how we get the correct Data.
            ListItem listItem = listOfData.get(
                    this.getAdapterPosition()
            );

            controller.onListItemClick(
                    listItem,
                    v
            );

        }
    }
}
