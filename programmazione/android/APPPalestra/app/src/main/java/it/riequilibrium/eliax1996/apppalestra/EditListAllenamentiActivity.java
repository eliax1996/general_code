package it.riequilibrium.eliax1996.apppalestra;

import android.content.Intent;
import android.os.Bundle;
import android.support.design.widget.BaseTransientBottomBar;
import android.support.design.widget.FloatingActionButton;
import android.support.design.widget.Snackbar;
import android.support.v4.content.ContextCompat;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.DividerItemDecoration;
import android.support.v7.widget.LinearLayoutManager;
import android.support.v7.widget.RecyclerView;
import android.support.v7.widget.Toolbar;
import android.support.v7.widget.helper.ItemTouchHelper;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;

import java.util.List;

import data.FakeDataSource;
import data.ListItem;
import logic.Controller;
import view.CustomAdapter;
import view.ViewInterface;

public class EditListAllenamentiActivity extends AppCompatActivity implements ViewInterface {

    // url = https://www.androidhive.info/2017/09/android-recyclerview-swipe-delete-undo-using-itemtouchhelper/

    private RecyclerView recyclerView;
    private LayoutInflater layoutInflater;
    private Controller controller;
    private List<ListItem> listOfData;
    private CustomAdapter customAdapter;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_edit_list_allenamenti);

        recyclerView = (RecyclerView) findViewById(R.id.rec_list_activity);
        layoutInflater = getLayoutInflater();
        Toolbar toolbar = (Toolbar) findViewById(R.id.toolbarEditListActivity);
        setSupportActionBar(toolbar);

        toolbar.setTitle("modifica allenamento");
        toolbar.setOnMenuItemClickListener(new Toolbar.OnMenuItemClickListener() {
            @Override
            public boolean onMenuItemClick(MenuItem item) {
                Snackbar.make(getWindow().getDecorView(),"back pressed", Snackbar.LENGTH_SHORT)
                        .setAction("Action", new View.OnClickListener() {
                            @Override
                            public void onClick(View v) {
                                // azione dopo aver premuto l'azione
                            }
                        });
                return false;
            }
        });
        toolbar.setTitleMarginStart(72);

        FloatingActionButton fab = (FloatingActionButton) findViewById(R.id.fab);
        fab.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Snackbar.make(view, "Replace with your own action", Snackbar.LENGTH_LONG)
                        .setAction("Action", null).show();
            }
        });

        controller = new Controller(this, new FakeDataSource());

        getSupportActionBar().setHomeButtonEnabled(true);
        getSupportActionBar().setDisplayHomeAsUpEnabled(true);

        // aggiungo un elemento alla lista
        controller.createNewListItem();
    }



















    // porzione di codice dovuta all'implementazione del controller della ViewInterface

    // imposto parametri della view e dell'adapter
    @Override
    public void setUpAdapterAndView(List<ListItem> listOfData) {

        this.listOfData = listOfData;
        LinearLayoutManager layoutManager = new LinearLayoutManager(this);

        recyclerView.setLayoutManager(layoutManager);

        customAdapter = new CustomAdapter(layoutInflater,listOfData,controller);
        recyclerView.setAdapter(customAdapter);

        DividerItemDecoration itemDecoration = new DividerItemDecoration(
                recyclerView.getContext(),
                layoutManager.getOrientation()
        );

        itemDecoration.setDrawable(
                ContextCompat.getDrawable(
                        EditListAllenamentiActivity.this,
                        R.drawable.divider_white
                )
        );

        recyclerView.addItemDecoration(
                itemDecoration
        );

        ItemTouchHelper itemTouchHelper = new ItemTouchHelper(createHelperCallback());
        itemTouchHelper.attachToRecyclerView(recyclerView);

    }

    // aggiungo un nuovo elemento alla lista
    @Override
    public void addNewListItemToView(ListItem newItem) {
        listOfData.add(newItem);
        int endOfList = listOfData.size() - 1;

        customAdapter.notifyItemInserted(endOfList);
        recyclerView.smoothScrollToPosition(endOfList);
    }

    // rimuovo un elemento dalla lista
    @Override
    public void deleteListItemAt(int position) {
        listOfData.remove(position);
        customAdapter.notifyItemRemoved(position);
    }

    // mostra la snackbar e permetti di annullare l'eliminazione
    @Override
    public void showUndoSnackbar() {
        Snackbar.make(
                getWindow().getDecorView(),
                "elemento eliminato",
                Snackbar.LENGTH_LONG
        )
                .setAction("annulla", new View.OnClickListener() {
                    @Override
                    public void onClick(View v) {
                        controller.onUndoConfirmed();
                    }
                })
                .addCallback(new BaseTransientBottomBar.BaseCallback<Snackbar>() {
                    @Override
                    public void onDismissed(Snackbar transientBottomBar, int event) {
                        super.onDismissed(transientBottomBar, event);

                        controller.onSnackbarTimeout();
                    }
                })
                .show();
    }

    // imposta un elemento a una posizione X
    @Override
    public void insertListItemAt(int position, ListItem listItem) {
        listOfData.add(position, listItem);
        customAdapter.notifyItemInserted(position);
        Log.d("element list","spostato un elemento della lista");
    }



    // metodo che crea una funzione per gestire la chiamata di un elemento per quando viene toccato
    private ItemTouchHelper.Callback createHelperCallback() {
        /*First Param is for Up/Down motion, second is for Left/Right.
        Note that we can supply 0, one constant (e.g. ItemTouchHelper.LEFT), or two constants (e.g.
        ItemTouchHelper.LEFT | ItemTouchHelper.RIGHT) to specify what directions are allowed.
        */
        ItemTouchHelper.SimpleCallback simpleItemTouchCallback = new ItemTouchHelper.SimpleCallback(
                0,
                ItemTouchHelper.LEFT | ItemTouchHelper.RIGHT) {

            //not used, as the first parameter above is 0
            @Override
            public boolean onMove(RecyclerView recyclerView, RecyclerView.ViewHolder viewHolder,
                                  RecyclerView.ViewHolder target) {
                return false;
            }


            @Override
            public void onSwiped(final RecyclerView.ViewHolder viewHolder, int swipeDir) {
                int position = viewHolder.getAdapterPosition();
                controller.onListItemSwiped(
                        position,
                        listOfData.get(position)
                );
            }
        };

        return simpleItemTouchCallback;
    }

    // per tornare al menù precedente
    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        if (item.getItemId() == android.R.id.home){
            Intent intent = new Intent(getApplicationContext(),MainActivity.class);
            startActivity(intent);
        }

        return super.onOptionsItemSelected(item);
    }
}
